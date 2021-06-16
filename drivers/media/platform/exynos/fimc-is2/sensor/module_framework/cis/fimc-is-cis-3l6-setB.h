/*
 * Samsung Exynos5 SoC series Sensor driver
 *
 *
 * Copyright (c) 2011 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef FIMC_IS_CIS_3L6_SET_B_H
#define FIMC_IS_CIS_3L6_SET_B_H

#include "fimc-is-cis.h"
#include "fimc-is-cis-3l6.h"


/*
File used: 3L6_EVT1_Ver_1.8.xlsx
version : 1.8
MIPI clck : 1126 MHz
ext clk : 26 MHz
*/

const u32 sensor_3l6_setfile_B_Global[] = {

	0x306A,	0x2F4C, 0x02,
	0x306C,	0xCA01, 0x02,
	0x307A,	0x0D20, 0x02,
	0x309E,	0x002D, 0x02,
	0x3072,	0x0013, 0x02,
	0x3074,	0x0977, 0x02,
	0x3076,	0x9411, 0x02,
	0x3024,	0x0016, 0x02,
	0x3002,	0x0E00, 0x02,
	0x3006,	0x1000, 0x02,
	0x300A,	0x0C00, 0x02,
	0x3018,	0xC500, 0x02,
	0x303A,	0x0204, 0x02,
	0x3266,	0x0001, 0x02,
	0x38DA,	0x000E, 0x02,
	0x38DC,	0x000B, 0x02,
	0x38D6,	0x000A, 0x02,
	0x3070,	0x3D00, 0x02,
	0x3084,	0x1314, 0x02,
	0x3086,	0x0CE7, 0x02,
	0x3004,	0x0800, 0x02,
	0x3C66,	0x0100, 0x02,	// Master mode disable
};
const u32 sensor_3l6_setfile_B_4128x3096_30fps[] = {
	//mode change   Single Still Capture (4:3)
	0x314A, 0x5F00, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x001A, 0x02,
	0x32B2, 0x0000, 0x02,
	0x32B4, 0x0000, 0x02,
	0x32B6, 0x0000, 0x02,
	0x32B8, 0x0000, 0x02,
	0x3090, 0x8800, 0x02,
	0x3238, 0x000C, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0030, 0x02,
	0x0348, 0x104F, 0x02,
	0x0346, 0x0014, 0x02,
	0x034A, 0x0C2B, 0x02,
	0x034C, 0x1020, 0x02,
	0x034E, 0x0C18, 0x02,
	0x0202, 0x03DE, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E42, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0CC1, 0x02,
	0x0900, 0x0000, 0x02,
	0x0386, 0x0001, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};
const u32 sensor_3l6_setfile_B_4128x2324_30fps[] = {
	//mode change Single Still Capture (16:9)
	0x314A,	0x5F00, 0x02,
	0x3064,	0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x001A, 0x02,
	0x32B2, 0x0000, 0x02,
	0x32B4, 0x0000, 0x02,
	0x32B6, 0x0000, 0x02,
	0x32B8, 0x0000, 0x02,
	0x3090, 0x8800, 0x02,
	0x3238, 0x000C, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0030, 0x02,
	0x0348, 0x104F, 0x02,
	0x0346, 0x0196, 0x02,
	0x034A, 0x0AA9, 0x02,
	0x034C, 0x1020, 0x02,
	0x034E, 0x0914, 0x02,
	0x0202, 0x03DE, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E42, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0CC1, 0x02,
	0x0900, 0x0000, 0x02,
	0x0386, 0x0001, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};
const u32 sensor_3l6_setfile_B_4128x2008_30fps[] = {
	//mode change Single Still Capture (18.5:9)
	0x314A, 0x5F00,	0x02,
	0x3064, 0xFFCF,	0x02,
	0x3066, 0x7E00,	0x02,
	0x309C, 0x0640,	0x02,
	0x380C, 0x001A,	0x02,
	0x32B2, 0x0000,	0x02,
	0x32B4, 0x0000,	0x02,
	0x32B6, 0x0000,	0x02,
	0x32B8, 0x0000,	0x02,
	0x3090, 0x8800,	0x02,
	0x3238, 0x000C,	0x02,
	0x0100, 0x0000,	0x02,
	0x0344, 0x0030,	0x02,
	0x0348, 0x104F,	0x02,
	0x0346, 0x0234,	0x02,
	0x034A, 0x0A0B,	0x02,
	0x034C, 0x1020,	0x02,
	0x034E, 0x07D8,	0x02,
	0x0202, 0x03DE,	0x02,
	0x3400, 0x0000,	0x02,
	0x3402, 0x4E42,	0x02,
	0x0136, 0x1A00,	0x02,
	0x0304, 0x0003,	0x02,
	0x0306, 0x0053,	0x02,
	0x030C, 0x0004,	0x02,
	0x030E, 0x005C,	0x02,
	0x3C16, 0x0000,	0x02,
	0x0342, 0x1320,	0x02,
	0x0340, 0x0CC1,	0x02,
	0x0900, 0x0000,	0x02,
	0x0386, 0x0001,	0x02,
	0x3452, 0x0000,	0x02,
	0x345A, 0x0000,	0x02,
	0x345C, 0x0000,	0x02,
	0x345E, 0x0000,	0x02,
	0x3460, 0x0000,	0x02,
	0x38C4, 0x0009,	0x02,
	0x38D8, 0x002A,	0x02,
	0x38DA, 0x000A,	0x02,
	0x38DC, 0x000B,	0x02,
	0x38C2, 0x000A,	0x02,
	0x38C0, 0x000F,	0x02,
	0x38D6, 0x000A,	0x02,
	0x38D4, 0x0009,	0x02,
	0x38B0, 0x000F,	0x02,
	0x3932, 0x1000,	0x02,
	0x0820, 0x04AC,	0x02,
	0x3C34, 0x0008,	0x02,
	0x3C36, 0x2800,	0x02,
	0x3C38, 0x0028,	0x02,
	0x393E, 0x4000,	0x02,
};
const u32 sensor_3l6_setfile_B_3088x3088_30fps[] = {
	//mode change  Single Still Capture (1:1)
	0x314A, 0x5F00, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x006A, 0x02,
	0x32B2, 0x0000, 0x02,
	0x32B4, 0x0000, 0x02,
	0x32B6, 0x0000, 0x02,
	0x32B8, 0x0000, 0x02,
	0x3090, 0x8800, 0x02,
	0x3238, 0x000C, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0238, 0x02,
	0x0348, 0x0E47, 0x02,
	0x0346, 0x0018, 0x02,
	0x034A, 0x0C27, 0x02,
	0x034C, 0x0C10, 0x02,
	0x034E, 0x0C10, 0x02,
	0x0202, 0x03DE, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E42, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0CC1, 0x02,
	0x0900, 0x0000, 0x02,
	0x0386, 0x0001, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const u32 sensor_3l6_setfile_B_4128x1908_30fps[] = {
	/* 19.5:9 ratio */
	0x314A, 0x5F00, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x001A, 0x02,
	0x32B2, 0x0000, 0x02,
	0x32B4, 0x0000, 0x02,
	0x32B6, 0x0000, 0x02,
	0x32B8, 0x0000, 0x02,
	0x3090, 0x8800, 0x02,
	0x3238, 0x000C, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0030, 0x02,
	0x0348, 0x104F, 0x02,
	0x0346, 0x0266, 0x02,
	0x034A, 0x09D9, 0x02,
	0x034C, 0x1020, 0x02,
	0x034E, 0x0774, 0x02,
	0x0202, 0x03DE, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E42, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0CC1, 0x02,
	0x0900, 0x0000, 0x02,
	0x0386, 0x0001, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const u32 sensor_3l6_setfile_B_4128x1956_30fps[] = {
	/* 19:9 ratio */
	0x314A, 0x5F00, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x001A, 0x02,
	0x32B2, 0x0000, 0x02,
	0x32B4, 0x0000, 0x02,
	0x32B6, 0x0000, 0x02,
	0x32B8, 0x0000, 0x02,
	0x3090, 0x8800, 0x02,
	0x3238, 0x000C, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0030, 0x02,
	0x0348, 0x104F, 0x02,
	0x0346, 0x024E, 0x02,
	0x034A, 0x09F1, 0x02,
	0x034C, 0x1020, 0x02,
	0x034E, 0x07A4, 0x02,
	0x0202, 0x03DE, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E42, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0CC1, 0x02,
	0x0900, 0x0000, 0x02,
	0x0386, 0x0001, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const u32 sensor_3l6_setfile_B_2064x1548_30fps[] = {
	/* VT Call 4:3 ratio */
	0x314A, 0x5F02, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x0090, 0x02,
	0x32B2, 0x0003, 0x02,
	0x32B4, 0x0003, 0x02,
	0x32B6, 0x0003, 0x02,
	0x32B8, 0x0003, 0x02,
	0x3090, 0x8000, 0x02,
	0x3238, 0x000B, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0030, 0x02,
	0x0348, 0x104F, 0x02,
	0x0346, 0x0014, 0x02,
	0x034A, 0x0C2B, 0x02,
	0x034C, 0x0810, 0x02,
	0x034E, 0x060C, 0x02,
	0x0202, 0x0656, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E46, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0CC1, 0x02,
	0x0900, 0x0122, 0x02,
	0x0386, 0x0003, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const u32 sensor_3l6_setfile_B_2064x1160_30fps[] = {
	/* VT Call 16:9 ratio */
	0x314A, 0x5F02, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x0090, 0x02,
	0x32B2, 0x0003, 0x02,
	0x32B4, 0x0003, 0x02,
	0x32B6, 0x0003, 0x02,
	0x32B8, 0x0003, 0x02,
	0x3090, 0x8000, 0x02,
	0x3238, 0x000B, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0030, 0x02,
	0x0348, 0x104F, 0x02,
	0x0346, 0x0198, 0x02,
	0x034A, 0x0AA7, 0x02,
	0x034C, 0x0810, 0x02,
	0x034E, 0x0488, 0x02,
	0x0202, 0x0656, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E46, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0CC1, 0x02,
	0x0900, 0x0122, 0x02,
	0x0386, 0x0003, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const u32 sensor_3l6_setfile_B_1536x1536_30fps[] = {
	/* VT Call 1:1 ratio */
	0x314A, 0x5F02, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x0090, 0x02,
	0x32B2, 0x0003, 0x02,
	0x32B4, 0x0003, 0x02,
	0x32B6, 0x0003, 0x02,
	0x32B8, 0x0003, 0x02,
	0x3090, 0x8000, 0x02,
	0x3238, 0x000B, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0240, 0x02,
	0x0348, 0x0E3F, 0x02,
	0x0346, 0x0020, 0x02,
	0x034A, 0x0C1F, 0x02,
	0x034C, 0x0600, 0x02,
	0x034E, 0x0600, 0x02,
	0x0202, 0x0656, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E46, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0CC1, 0x02,
	0x0900, 0x0122, 0x02,
	0x0386, 0x0003, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const u32 sensor_3l6_setfile_B_1028x772_120fps[] = {
	/*mode change	FAST AE (4:3) */
	0x314A, 0x5F00, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x0046, 0x02,
	0x32B2, 0x0006, 0x02,
	0x32B4, 0x0006, 0x02,
	0x32B6, 0x0006, 0x02,
	0x32B8, 0x0006, 0x02,
	0x3090, 0x8000, 0x02,
	0x3238, 0x000A, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0038, 0x02,
	0x0348, 0x1047, 0x02,
	0x0346, 0x0018, 0x02,
	0x034A, 0x0C27, 0x02,
	0x034C, 0x0404, 0x02,
	0x034E, 0x0304, 0x02,
	0x0202, 0x0329, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E46, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0330, 0x02,
	0x0900, 0x0144, 0x02,
	0x0386, 0x0007, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const u32 sensor_3l6_setfile_B_1280x720_120fps[] = {
	//mode change   Super Slow Motion(16:9 Crop)
	0x314A, 0x5F02, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x0050, 0x02,
	0x32B2, 0x0006, 0x02,
	0x32B4, 0x0006, 0x02,
	0x32B6, 0x0006, 0x02,
	0x32B8, 0x0006, 0x02,
	0x3090, 0x8000, 0x02,
	0x3238, 0x000B, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0340, 0x02,
	0x0348, 0x0D3F, 0x02,
	0x0346, 0x0350, 0x02,
	0x034A, 0x08EF, 0x02,
	0x034C, 0x0500, 0x02,
	0x034E, 0x02D0, 0x02,
	0x0202, 0x0656, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E46, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0330, 0x02,
	0x0900, 0x0122, 0x02,
	0x0386, 0x0003, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};
const u32 sensor_3l6_setfile_B_1052x780_120fps[] = {
	//mode change	FAST AE (4:3)
	0x314A, 0x5F00, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x0046, 0x02,
	0x32B2, 0x0006, 0x02,
	0x32B4, 0x0006, 0x02,
	0x32B6, 0x0006, 0x02,
	0x32B8, 0x0006, 0x02,
	0x3090, 0x8000, 0x02,
	0x3238, 0x000A, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0008, 0x02,
	0x0348, 0x1077, 0x02,
	0x0346, 0x0008, 0x02,
	0x034A, 0x0C37, 0x02,
	0x034C, 0x041C, 0x02,
	0x034E, 0x030C, 0x02,
	0x0202, 0x0329, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E46, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0330, 0x02,
	0x0900, 0x0144, 0x02,
	0x0386, 0x0007, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const u32 sensor_3l6_setfile_B_1024x768_120fps[] = {
	//mode change	FAST AE (4:3)
	0x314A, 0x5F00, 0x02,
	0x3064, 0xFFCF, 0x02,
	0x3066, 0x7E00, 0x02,
	0x309C, 0x0640, 0x02,
	0x380C, 0x0046, 0x02,
	0x32B2, 0x0006, 0x02,
	0x32B4, 0x0006, 0x02,
	0x32B6, 0x0006, 0x02,
	0x32B8, 0x0006, 0x02,
	0x3090, 0x8000, 0x02,
	0x3238, 0x000A, 0x02,
	0x0100, 0x0000, 0x02,
	0x0344, 0x0040, 0x02,
	0x0348, 0x103F, 0x02,
	0x0346, 0x0020, 0x02,
	0x034A, 0x0C1F, 0x02,
	0x034C, 0x0400, 0x02,
	0x034E, 0x0300, 0x02,
	0x0202, 0x0329, 0x02,
	0x3400, 0x0000, 0x02,
	0x3402, 0x4E46, 0x02,
	0x0136, 0x1A00, 0x02,
	0x0304, 0x0003, 0x02,
	0x0306, 0x0053, 0x02,
	0x030C, 0x0004, 0x02,
	0x030E, 0x005C, 0x02,
	0x3C16, 0x0000, 0x02,
	0x0342, 0x1320, 0x02,
	0x0340, 0x0330, 0x02,
	0x0900, 0x0144, 0x02,
	0x0386, 0x0007, 0x02,
	0x3452, 0x0000, 0x02,
	0x345A, 0x0000, 0x02,
	0x345C, 0x0000, 0x02,
	0x345E, 0x0000, 0x02,
	0x3460, 0x0000, 0x02,
	0x38C4, 0x0009, 0x02,
	0x38D8, 0x002A, 0x02,
	0x38DA, 0x000A, 0x02,
	0x38DC, 0x000B, 0x02,
	0x38C2, 0x000A, 0x02,
	0x38C0, 0x000F, 0x02,
	0x38D6, 0x000A, 0x02,
	0x38D4, 0x0009, 0x02,
	0x38B0, 0x000F, 0x02,
	0x3932, 0x1000, 0x02,
	0x0820, 0x04AC, 0x02,
	0x3C34, 0x0008, 0x02,
	0x3C36, 0x2800, 0x02,
	0x3C38, 0x0028, 0x02,
	0x393E, 0x4000, 0x02,
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_4128x3096_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x5C, /* vt_pix_clk_div	(0x0301) */
	0x04, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x01, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */

};

const struct sensor_pll_info sensor_3l6_pllinfo_B_4128x2324_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x01, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */

};

const struct sensor_pll_info sensor_3l6_pllinfo_B_4128x2008_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x01, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_3088x3088_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */

};

const struct sensor_pll_info sensor_3l6_pllinfo_B_4128x1908_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_4128x1956_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_2064x1548_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_2064x1160_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_1536x1536_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0CC1, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_1280x720_120fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x57, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0330, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_1052x780_120fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0330, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_1028x772_120fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0330, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

const struct sensor_pll_info sensor_3l6_pllinfo_B_1024x768_120fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	0x02, /* vt_pix_clk_div	(0x0301) */
	0x01, /* vt_sys_clk_div	(0x0303) */
	0x03, /* pre_pll_clk_div	(0x0305) */
	0x53, /* pll_multiplier	(0x0307) */
	0x08, /* op_pix_clk_div	(0x0309) */
	0x04, /* op_sys_clk_div	(0x030B) */

	0x04, /* secnd_pre_pll_clk_div	(0x030D) */
	0x5C, /* secnd_pll_multiplier	(0x030F) */
	0x0330, /* frame_length_lines	(0x0341) */
	0x1320, /* line_length_pck	(0x0343) */
};

static const u32 *sensor_3l6_setfiles_B[] = {
	sensor_3l6_setfile_B_4128x3096_30fps,
	sensor_3l6_setfile_B_4128x2324_30fps,
	sensor_3l6_setfile_B_4128x2008_30fps,
	sensor_3l6_setfile_B_3088x3088_30fps,
	sensor_3l6_setfile_B_4128x1956_30fps,
	sensor_3l6_setfile_B_4128x1908_30fps,
	sensor_3l6_setfile_B_2064x1548_30fps,
	sensor_3l6_setfile_B_2064x1160_30fps,
	sensor_3l6_setfile_B_1536x1536_30fps,
	sensor_3l6_setfile_B_1280x720_120fps,
	sensor_3l6_setfile_B_1028x772_120fps,
	sensor_3l6_setfile_B_1024x768_120fps,
};

static const u32 sensor_3l6_setfile_B_sizes[] = {
	sizeof(sensor_3l6_setfile_B_4128x3096_30fps) / sizeof(sensor_3l6_setfile_B_4128x3096_30fps[0]),
	sizeof(sensor_3l6_setfile_B_4128x2324_30fps) / sizeof(sensor_3l6_setfile_B_4128x2324_30fps[0]),
	sizeof(sensor_3l6_setfile_B_4128x2008_30fps) / sizeof(sensor_3l6_setfile_B_4128x2008_30fps[0]),
	sizeof(sensor_3l6_setfile_B_3088x3088_30fps) / sizeof(sensor_3l6_setfile_B_3088x3088_30fps[0]),
	sizeof(sensor_3l6_setfile_B_4128x1956_30fps) / sizeof(sensor_3l6_setfile_B_4128x1956_30fps[0]),
	sizeof(sensor_3l6_setfile_B_4128x1908_30fps) / sizeof(sensor_3l6_setfile_B_4128x1908_30fps[0]),
	sizeof(sensor_3l6_setfile_B_2064x1548_30fps) / sizeof(sensor_3l6_setfile_B_2064x1548_30fps[0]),
	sizeof(sensor_3l6_setfile_B_2064x1160_30fps) / sizeof(sensor_3l6_setfile_B_2064x1160_30fps[0]),
	sizeof(sensor_3l6_setfile_B_1536x1536_30fps) / sizeof(sensor_3l6_setfile_B_1536x1536_30fps[0]),
	sizeof(sensor_3l6_setfile_B_1280x720_120fps) / sizeof(sensor_3l6_setfile_B_1280x720_120fps[0]),
	sizeof(sensor_3l6_setfile_B_1028x772_120fps) / sizeof(sensor_3l6_setfile_B_1028x772_120fps[0]),
	sizeof(sensor_3l6_setfile_B_1024x768_120fps) / sizeof(sensor_3l6_setfile_B_1024x768_120fps[0]),
};

static const struct sensor_pll_info *sensor_3l6_pllinfos_B[] = {
	&sensor_3l6_pllinfo_B_4128x3096_30fps,
	&sensor_3l6_pllinfo_B_4128x2324_30fps,
	&sensor_3l6_pllinfo_B_4128x2008_30fps,
	&sensor_3l6_pllinfo_B_3088x3088_30fps,
	&sensor_3l6_pllinfo_B_4128x1956_30fps,
	&sensor_3l6_pllinfo_B_4128x1908_30fps,
	&sensor_3l6_pllinfo_B_2064x1548_30fps,
	&sensor_3l6_pllinfo_B_2064x1160_30fps,
	&sensor_3l6_pllinfo_B_1536x1536_30fps,
	&sensor_3l6_pllinfo_B_1280x720_120fps,
	&sensor_3l6_pllinfo_B_1028x772_120fps,
	&sensor_3l6_pllinfo_B_1024x768_120fps,
};

#endif

