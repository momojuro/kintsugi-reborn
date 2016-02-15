/*
 * drivers/cpufreq/cpufreq_governor.c
 *
 * CPUFREQ governors common code
 *
 * Copyright	(C) 2001 Russell King
 *		(C) 2003 Venkatesh Pallipadi <venkatesh.pallipadi@intel.com>.
 *		(C) 2003 Jun Nakajima <jun.nakajima@intel.com>
 *		(C) 2009 Alexander Clouter <alex@digriz.org.uk>
 *		(c) 2012 Viresh Kumar <viresh.kumar@linaro.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/export.h>
#include <linux/kernel_stat.h>
#include <linux/slab.h>

#include "cpufreq_governor.h"

#ifdef CONFIG_CPU_THERMAL_IPA
#include "cpu_load_metric.h"
#endif

DEFINE_MUTEX(dbs_data_mutex);
EXPORT_SYMBOL_GPL(dbs_data_mutex);

/* Common sysfs tunables */
/**
 * store_sampling_rate - update sampling rate effective immediately if needed.
 *
 * If new rate is smaller than the old, simply updating
 * dbs.sampling_rate might not be appropriate. For example, if the
 * original sampling_rate was 1 second and the requested new sampling rate is 10
 * ms because the user needs immediate reaction from ondemand governor, but not
 * sure if higher frequency will be required or not, then, the governor may
 * change the sampling rate too late; up to 1 second later. Thus, if we are
 * reducing the sampling rate, we need to make the new value effective
 * immediately.
 *
 * On the other hand, if new rate is larger than the old, then we may evaluate
 * the load too soon, and it might we worth updating sample_delay_ns then as
 * well.
 *
 * This must be called with dbs_data->mutex held, otherwise traversing
 * policy_dbs_list isn't safe.
 */
ssize_t store_sampling_rate(struct dbs_data *dbs_data, const char *buf,
			    size_t count)
{
	struct policy_dbs_info *policy_dbs;
	unsigned int rate;
	int ret;
	ret = sscanf(buf, "%u", &rate);
	if (ret != 1)
		return -EINVAL;

	dbs_data->sampling_rate = max(rate, dbs_data->min_sampling_rate);

	/*
	 * We are operating under dbs_data->mutex and so the list and its
	 * entries can't be freed concurrently.
	 */
	list_for_each_entry(policy_dbs, &dbs_data->policy_dbs_list, list) {
		mutex_lock(&policy_dbs->timer_mutex);
		/*
		 * On 32-bit architectures this may race with the
		 * sample_delay_ns read in dbs_update_util_handler(), but that
		 * really doesn't matter.  If the read returns a value that's
		 * too big, the sample will be skipped, but the next invocation
		 * of dbs_update_util_handler() (when the update has been
		 * completed) will take a sample.  If the returned value is too
		 * small, the sample will be taken immediately, but that isn't a
		 * problem, as we want the new rate to take effect immediately
		 * anyway.
		 *
		 * If this runs in parallel with dbs_work_handler(), we may end
		 * up overwriting the sample_delay_ns value that it has just
		 * written, but the difference should not be too big and it will
		 * be corrected next time a sample is taken, so it shouldn't be
		 * significant.
		 */
		gov_update_sample_delay(policy_dbs, dbs_data->sampling_rate);
		mutex_unlock(&policy_dbs->timer_mutex);
	}

	return count;
}
EXPORT_SYMBOL_GPL(store_sampling_rate);

static inline struct dbs_data *to_dbs_data(struct kobject *kobj)
{
	return container_of(kobj, struct dbs_data, kobj);
}

static inline struct governor_attr *to_gov_attr(struct attribute *attr)
{
	return container_of(attr, struct governor_attr, attr);
}

static ssize_t governor_show(struct kobject *kobj, struct attribute *attr,
			     char *buf)
{
	struct dbs_data *dbs_data = to_dbs_data(kobj);
	struct governor_attr *gattr = to_gov_attr(attr);
	int ret = -EIO;

	if (gattr->show)
		ret = gattr->show(dbs_data, buf);

	return ret;
}

static ssize_t governor_store(struct kobject *kobj, struct attribute *attr,
			      const char *buf, size_t count)
{
	struct dbs_data *dbs_data = to_dbs_data(kobj);
	struct governor_attr *gattr = to_gov_attr(attr);
	int ret = -EIO;

	mutex_lock(&dbs_data->mutex);

	if (gattr->store)
		ret = gattr->store(dbs_data, buf, count);

	mutex_unlock(&dbs_data->mutex);

	return ret;
}

/*
 * Sysfs Ops for accessing governor attributes.
 *
 * All show/store invocations for governor specific sysfs attributes, will first
 * call the below show/store callbacks and the attribute specific callback will
 * be called from within it.
 */
static const struct sysfs_ops governor_sysfs_ops = {
	.show	= governor_show,
	.store	= governor_store,
};

void dbs_check_cpu(struct cpufreq_policy *policy)
{
	int cpu = policy->cpu;
	struct dbs_governor *gov = dbs_governor_of(policy);
	struct policy_dbs_info *policy_dbs = policy->governor_data;
	struct dbs_data *dbs_data = policy_dbs->dbs_data;
	struct od_dbs_tuners *od_tuners = dbs_data->tuners;
	unsigned int sampling_rate = dbs_data->sampling_rate;
	unsigned int ignore_nice = dbs_data->ignore_nice_load;
	unsigned int max_load = 0;
	unsigned int j;

	if (gov->governor == GOV_ONDEMAND) {
		struct od_cpu_dbs_info_s *od_dbs_info =
				gov->get_cpu_dbs_info_s(cpu);

		/*
		 * Sometimes, the ondemand governor uses an additional
		 * multiplier to give long delays. So apply this multiplier to
		 * the 'sampling_rate', so as to keep the wake-up-from-idle
		 * detection logic a bit conservative.
		 */
		sampling_rate *= od_dbs_info->rate_mult;

	}

	/* Get Absolute Load */
	for_each_cpu(j, policy->cpus) {
		struct cpu_dbs_info *j_cdbs;
		u64 cur_wall_time, cur_idle_time;
		unsigned int idle_time, wall_time;
		unsigned int load;
		int io_busy = 0;

		j_cdbs = gov->get_cpu_cdbs(j);

		/*
		 * For the purpose of ondemand, waiting for disk IO is
		 * an indication that you're performance critical, and
		 * not that the system is actually idle. So do not add
		 * the iowait time to the cpu idle time.
		 */
		if (gov->governor == GOV_ONDEMAND)
			io_busy = od_tuners->io_is_busy;
		cur_idle_time = get_cpu_idle_time(j, &cur_wall_time, io_busy);

		wall_time = (unsigned int)
			(cur_wall_time - j_cdbs->prev_cpu_wall);
		j_cdbs->prev_cpu_wall = cur_wall_time;

		if (cur_idle_time < j_cdbs->prev_cpu_idle)
			cur_idle_time = j_cdbs->prev_cpu_idle;

		idle_time = (unsigned int)
			(cur_idle_time - j_cdbs->prev_cpu_idle);
		j_cdbs->prev_cpu_idle = cur_idle_time;

		if (ignore_nice) {
			struct cpu_dbs_info *cdbs = gov->get_cpu_cdbs(cpu);
			u64 cur_nice;
			unsigned long cur_nice_jiffies;

			cur_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE] -
					 cdbs->prev_cpu_nice;
			/*
			 * Assumption: nice time between sampling periods will
			 * be less than 2^32 jiffies for 32 bit sys
			 */
			cur_nice_jiffies = (unsigned long)
					cputime64_to_jiffies64(cur_nice);

			cdbs->prev_cpu_nice =
				kcpustat_cpu(j).cpustat[CPUTIME_NICE];
			idle_time += jiffies_to_usecs(cur_nice_jiffies);
		}

		if (unlikely(!wall_time || wall_time < idle_time))
			continue;

		/*
		 * If the CPU had gone completely idle, and a task just woke up
		 * on this CPU now, it would be unfair to calculate 'load' the
		 * usual way for this elapsed time-window, because it will show
		 * near-zero load, irrespective of how CPU intensive that task
		 * actually is. This is undesirable for latency-sensitive bursty
		 * workloads.
		 *
		 * To avoid this, we reuse the 'load' from the previous
		 * time-window and give this task a chance to start with a
		 * reasonably high CPU frequency. (However, we shouldn't over-do
		 * this copy, lest we get stuck at a high load (high frequency)
		 * for too long, even when the current system load has actually
		 * dropped down. So we perform the copy only once, upon the
		 * first wake-up from idle.)
		 *
		 * Detecting this situation is easy: the governor's utilization
		 * update handler would not have run during CPU-idle periods.
		 * Hence, an unusually large 'wall_time' (as compared to the
		 * sampling rate) indicates this scenario.
		 *
		 * prev_load can be zero in two cases and we must recalculate it
		 * for both cases:
		 * - during long idle intervals
		 * - explicitly set to zero
		 */
		if (unlikely(wall_time > (2 * sampling_rate) &&
			     j_cdbs->prev_load)) {
			load = j_cdbs->prev_load;

			/*
			 * Perform a destructive copy, to ensure that we copy
			 * the previous load only once, upon the first wake-up
			 * from idle.
			 */
			j_cdbs->prev_load = 0;
		} else {
			load = 100 * (wall_time - idle_time) / wall_time;
			j_cdbs->prev_load = load;
		}

		if (load > max_load)
			max_load = load;

#ifdef CONFIG_CPU_THERMAL_IPA
		update_cpu_metric(j, cur_wall_time, idle_time, wall_time, policy);
#endif
	}

	gov->gov_check_cpu(cpu, max_load);
}
EXPORT_SYMBOL_GPL(dbs_check_cpu);

void gov_set_update_util(struct policy_dbs_info *policy_dbs,
			 unsigned int delay_us)
{
	struct cpufreq_policy *policy = policy_dbs->policy;
	struct dbs_governor *gov = dbs_governor_of(policy);
	int cpu;

	gov_update_sample_delay(policy_dbs, delay_us);
	policy_dbs->last_sample_time = 0;

	for_each_cpu(cpu, policy->cpus) {
		struct cpu_dbs_info *cdbs = gov->get_cpu_cdbs(cpu);

		cpufreq_set_update_util_data(cpu, &cdbs->update_util);
	}
}
EXPORT_SYMBOL_GPL(gov_set_update_util);

static inline void gov_clear_update_util(struct cpufreq_policy *policy)
{
	int i;

	for_each_cpu(i, policy->cpus)
		cpufreq_set_update_util_data(i, NULL);

	synchronize_rcu();
}

static void gov_cancel_work(struct cpufreq_policy *policy)
{
	struct policy_dbs_info *policy_dbs = policy->governor_data;

	gov_clear_update_util(policy_dbs->policy);
	irq_work_sync(&policy_dbs->irq_work);
	cancel_work_sync(&policy_dbs->work);
	atomic_set(&policy_dbs->work_count, 0);
}

static void dbs_work_handler(struct work_struct *work)
{
	struct policy_dbs_info *policy_dbs;
	struct cpufreq_policy *policy;
	struct dbs_governor *gov;
	unsigned int delay;

	policy_dbs = container_of(work, struct policy_dbs_info, work);
	policy = policy_dbs->policy;
	gov = dbs_governor_of(policy);

	/*
	 * Make sure cpufreq_governor_limits() isn't evaluating load or the
	 * ondemand governor isn't updating the sampling rate in parallel.
	 */
	mutex_lock(&policy_dbs->timer_mutex);
	delay = gov->gov_dbs_timer(policy);
	policy_dbs->sample_delay_ns = jiffies_to_nsecs(delay);
	mutex_unlock(&policy_dbs->timer_mutex);

	/*
	 * If the atomic operation below is reordered with respect to the
	 * sample delay modification, the utilization update handler may end
	 * up using a stale sample delay value.
	 */
	smp_mb__before_atomic();
	atomic_dec(&policy_dbs->work_count);
}

static void dbs_irq_work(struct irq_work *irq_work)
{
	struct policy_dbs_info *policy_dbs;

	policy_dbs = container_of(irq_work, struct policy_dbs_info, irq_work);
	schedule_work(&policy_dbs->work);
}

static void dbs_update_util_handler(struct update_util_data *data, u64 time,
				    unsigned long util, unsigned long max)
{
	struct cpu_dbs_info *cdbs = container_of(data, struct cpu_dbs_info, update_util);
	struct policy_dbs_info *policy_dbs = cdbs->policy_dbs;

	/*
	 * The work may not be allowed to be queued up right now.
	 * Possible reasons:
	 * - Work has already been queued up or is in progress.
	 * - It is too early (too little time from the previous sample).
	 */
	if (atomic_inc_return(&policy_dbs->work_count) == 1) {
		u64 delta_ns;

		delta_ns = time - policy_dbs->last_sample_time;
		if ((s64)delta_ns >= policy_dbs->sample_delay_ns) {
			policy_dbs->last_sample_time = time;
			irq_work_queue(&policy_dbs->irq_work);
			return;
		}
	}
	atomic_dec(&policy_dbs->work_count);
}

static struct policy_dbs_info *alloc_policy_dbs_info(struct cpufreq_policy *policy,
						     struct dbs_governor *gov)
{
	struct policy_dbs_info *policy_dbs;
	int j;

	/* Allocate memory for the common information for policy->cpus */
	policy_dbs = kzalloc(sizeof(*policy_dbs), GFP_KERNEL);
	if (!policy_dbs)
		return NULL;

	policy_dbs->policy = policy;
	mutex_init(&policy_dbs->timer_mutex);
	atomic_set(&policy_dbs->work_count, 0);
	init_irq_work(&policy_dbs->irq_work, dbs_irq_work);
	INIT_WORK(&policy_dbs->work, dbs_work_handler);

	/* Set policy_dbs for all CPUs, online+offline */
	for_each_cpu(j, policy->related_cpus) {
		struct cpu_dbs_info *j_cdbs = gov->get_cpu_cdbs(j);

		j_cdbs->policy_dbs = policy_dbs;
		j_cdbs->update_util.func = dbs_update_util_handler;
	}
	return policy_dbs;
}

static void free_policy_dbs_info(struct cpufreq_policy *policy,
				 struct dbs_governor *gov)
{
	struct cpu_dbs_info *cdbs = gov->get_cpu_cdbs(policy->cpu);
	struct policy_dbs_info *policy_dbs = cdbs->policy_dbs;
	int j;

	mutex_destroy(&policy_dbs->timer_mutex);

	for_each_cpu(j, policy->related_cpus) {
		struct cpu_dbs_info *j_cdbs = gov->get_cpu_cdbs(j);

		j_cdbs->policy_dbs = NULL;
		j_cdbs->update_util.func = NULL;
	}
	kfree(policy_dbs);
}

static int cpufreq_governor_init(struct cpufreq_policy *policy)
{
	struct dbs_governor *gov = dbs_governor_of(policy);
	struct dbs_data *dbs_data = gov->gdbs_data;
	struct policy_dbs_info *policy_dbs;
	unsigned int latency;
	int ret;

	/* State should be equivalent to EXIT */
	if (policy->governor_data)
		return -EBUSY;

	policy_dbs = alloc_policy_dbs_info(policy, gov);
	if (!policy_dbs)
		return -ENOMEM;

	if (dbs_data) {
		if (WARN_ON(have_governor_per_policy())) {
			ret = -EINVAL;
			goto free_policy_dbs_info;
		}
		policy_dbs->dbs_data = dbs_data;
		policy->governor_data = policy_dbs;

		mutex_lock(&dbs_data->mutex);
		dbs_data->usage_count++;
		list_add(&policy_dbs->list, &dbs_data->policy_dbs_list);
		mutex_unlock(&dbs_data->mutex);

		return 0;
	}

	dbs_data = kzalloc(sizeof(*dbs_data), GFP_KERNEL);
	if (!dbs_data) {
		ret = -ENOMEM;
		goto free_policy_dbs_info;
	}

	INIT_LIST_HEAD(&dbs_data->policy_dbs_list);
	mutex_init(&dbs_data->mutex);

	ret = gov->init(dbs_data, !policy->governor->initialized);
	if (ret)
		goto free_policy_dbs_info;

	/* policy latency is in ns. Convert it to us first */
	latency = policy->cpuinfo.transition_latency / 1000;
	if (latency == 0)
		latency = 1;

	/* Bring kernel and HW constraints together */
	dbs_data->min_sampling_rate = max(dbs_data->min_sampling_rate,
					  MIN_LATENCY_MULTIPLIER * latency);
	dbs_data->sampling_rate = max(dbs_data->min_sampling_rate,
				      LATENCY_MULTIPLIER * latency);

	if (!have_governor_per_policy())
		gov->gdbs_data = dbs_data;

	policy->governor_data = policy_dbs;

	policy_dbs->dbs_data = dbs_data;
	dbs_data->usage_count = 1;
	list_add(&policy_dbs->list, &dbs_data->policy_dbs_list);

	gov->kobj_type.sysfs_ops = &governor_sysfs_ops;
	ret = kobject_init_and_add(&dbs_data->kobj, &gov->kobj_type,
				   get_governor_parent_kobj(policy),
				   "%s", gov->gov.name);
	if (!ret)
		return 0;

	/* Failure, so roll back. */
	pr_err("cpufreq: Governor initialization failed (dbs_data kobject init error %d)\n", ret);

	policy->governor_data = NULL;

	if (!have_governor_per_policy())
		gov->gdbs_data = NULL;
	gov->exit(dbs_data, !policy->governor->initialized);
	kfree(dbs_data);

free_policy_dbs_info:
	free_policy_dbs_info(policy, gov);
	return ret;
}

static int cpufreq_governor_exit(struct cpufreq_policy *policy)
{
	struct dbs_governor *gov = dbs_governor_of(policy);
	struct policy_dbs_info *policy_dbs = policy->governor_data;
	struct dbs_data *dbs_data = policy_dbs->dbs_data;
	int count;

	mutex_lock(&dbs_data->mutex);
	list_del(&policy_dbs->list);
	count = --dbs_data->usage_count;
	mutex_unlock(&dbs_data->mutex);

	if (!count) {
		kobject_put(&dbs_data->kobj);

		policy->governor_data = NULL;

		if (!have_governor_per_policy())
			gov->gdbs_data = NULL;

		gov->exit(dbs_data, policy->governor->initialized == 1);
		mutex_destroy(&dbs_data->mutex);
		kfree(dbs_data);
	} else {
		policy->governor_data = NULL;
	}

	free_policy_dbs_info(policy, gov);
	return 0;
}

static int cpufreq_governor_start(struct cpufreq_policy *policy)
{
	struct dbs_governor *gov = dbs_governor_of(policy);
	struct policy_dbs_info *policy_dbs = policy->governor_data;
	struct dbs_data *dbs_data = policy_dbs->dbs_data;
	unsigned int sampling_rate, ignore_nice, j, cpu = policy->cpu;
	int io_busy = 0;

	if (!policy->cur)
		return -EINVAL;

	sampling_rate = dbs_data->sampling_rate;
	ignore_nice = dbs_data->ignore_nice_load;

	if (gov->governor == GOV_ONDEMAND) {
		struct od_dbs_tuners *od_tuners = dbs_data->tuners;

		io_busy = od_tuners->io_is_busy;
	}

	for_each_cpu(j, policy->cpus) {
		struct cpu_dbs_info *j_cdbs = gov->get_cpu_cdbs(j);
		unsigned int prev_load;

		j_cdbs->prev_cpu_idle =
			get_cpu_idle_time(j, &j_cdbs->prev_cpu_wall, io_busy);

		prev_load = (unsigned int)(j_cdbs->prev_cpu_wall -
					    j_cdbs->prev_cpu_idle);
		j_cdbs->prev_load = 100 * prev_load /
				    (unsigned int)j_cdbs->prev_cpu_wall;

		if (ignore_nice)
			j_cdbs->prev_cpu_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
	}

	if (gov->governor == GOV_CONSERVATIVE) {
		struct cs_cpu_dbs_info_s *cs_dbs_info =
			gov->get_cpu_dbs_info_s(cpu);

		cs_dbs_info->down_skip = 0;
		cs_dbs_info->requested_freq = policy->cur;
	} else {
		struct od_ops *od_ops = gov->gov_ops;
		struct od_cpu_dbs_info_s *od_dbs_info = gov->get_cpu_dbs_info_s(cpu);

		od_dbs_info->rate_mult = 1;
		od_dbs_info->sample_type = OD_NORMAL_SAMPLE;
		od_ops->powersave_bias_init_cpu(cpu);
	}

	gov_set_update_util(policy_dbs, sampling_rate);
	return 0;
}

static int cpufreq_governor_stop(struct cpufreq_policy *policy)
{
	gov_cancel_work(policy);

	return 0;
}

static int cpufreq_governor_limits(struct cpufreq_policy *policy)
{
	struct policy_dbs_info *policy_dbs = policy->governor_data;

	mutex_lock(&policy_dbs->timer_mutex);
	if (policy->max < policy->cur)
		__cpufreq_driver_target(policy, policy->max, CPUFREQ_RELATION_H);
	else if (policy->min > policy->cur)
		__cpufreq_driver_target(policy, policy->min, CPUFREQ_RELATION_L);
	dbs_check_cpu(policy);
	mutex_unlock(&policy_dbs->timer_mutex);

	return 0;
}

int cpufreq_governor_dbs(struct cpufreq_policy *policy, unsigned int event)
{
	int ret = -EINVAL;

	/* Lock governor to block concurrent initialization of governor */
	mutex_lock(&dbs_data_mutex);

	if (event == CPUFREQ_GOV_POLICY_INIT) {
		ret = cpufreq_governor_init(policy);
	} else if (policy->governor_data) {
		switch (event) {
		case CPUFREQ_GOV_POLICY_EXIT:
			ret = cpufreq_governor_exit(policy);
			break;
		case CPUFREQ_GOV_START:
			ret = cpufreq_governor_start(policy);
			break;
		case CPUFREQ_GOV_STOP:
			ret = cpufreq_governor_stop(policy);
			break;
		case CPUFREQ_GOV_LIMITS:
			ret = cpufreq_governor_limits(policy);
			break;
		}
	}

	mutex_unlock(&dbs_data_mutex);
	return ret;
}
EXPORT_SYMBOL_GPL(cpufreq_governor_dbs);
