/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2018-2020, The Linux Foundation. All rights reserved.
 */

#ifndef _SWR_SLAVE_PORT_CONFIG
#define _SWR_SLAVE_PORT_CONFIG

#include <soc/swr-common.h>

#define WSA_MSTR_PORT_MASK 0xFF
/*
 * Add port configuration in the format
 *{ si, off1, off2, hstart, hstop, wd_len, bp_mode, bgp_ctrl, lane_ctrl, dir,
 *  stream_type}
 */

/* DUMMY */
static struct port_params tx_dummy[SWR_MSTR_PORT_LEN] = {
	{0,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{0,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
	{0,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
};

/* AMIC 9.6 MHz clock */
#ifdef CONFIG_SND_SOC_HOLI
static struct port_params tx_wcd_9p6MHz[SWR_MSTR_PORT_LEN] = {
#ifndef CONFIG_MACH_XIAOMI
	{3,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX1 */
	{3,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
	{3,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX4 */
#else
	{7,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX1 */
	{7,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX3 */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX4 */
#endif
};
#else
static struct port_params tx_wcd_9p6MHz[SWR_MSTR_PORT_LEN] = {
	{3,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX1 */
	{7,  5,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX4 */
};
#endif

/* AMIC 4.8 MHz clock */
static struct port_params tx_wcd_4p8MHz[SWR_MSTR_PORT_LEN] = {
#ifndef CONFIG_MACH_XIAOMI
	{3,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX1 */
	{3,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
	{3,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX4 */
#else
	{7,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX1 */
	{7,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX3 */
	{7,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX4 */
#endif
};

/* AMIC 0.6 MHz clock, single channel */
static struct port_params tx_wcd_0p6MHz[SWR_MSTR_PORT_LEN] = {
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX4 */
};

/* 4 Channel configuration */
/* SWR DMIC0 */
static struct port_params tx_bottom_mic_9p6MHz[SWR_MSTR_PORT_LEN] = {
	{7,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{7,  6,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC1 */
static struct port_params tx_receiver_mic_9p6MHz[SWR_MSTR_PORT_LEN] = {
	{7,  4,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{7,  7,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC2 */
static struct port_params tx_back_mic_9p6MHz[SWR_MSTR_PORT_LEN] = {
	{7,  3,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC3 */
static struct port_params tx_top_mic_9p6MHz[SWR_MSTR_PORT_LEN] = {
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{7,  5,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* The 4.8MHZ port config is used in
 * 1. single mic standalone in "high power" mode
 * 2. dual mic standalone in "high power" mode
 * 3. sva standalone single/dual/tri/quad in "low-power" mode
 * 4. sva single/dmic in "low-power" + single mic in "high power" concurrency
 */
/* SWR DMIC0 */
static struct port_params tx_bottom_mic_4p8MHz[SWR_MSTR_PORT_LEN] = {
#ifndef CONFIG_MACH_XIAOMI
	{3,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
#else
	{7,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
#endif
	{15,  4,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC1 */
static struct port_params tx_receiver_mic_4p8MHz[SWR_MSTR_PORT_LEN] = {
#ifndef CONFIG_MACH_XIAOMI
	{3,  3,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
#else
	{7,  3,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
#endif
	{7,  6,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC2 */
static struct port_params tx_back_mic_4p8MHz[SWR_MSTR_PORT_LEN] = {
#ifndef CONFIG_MACH_XIAOMI
	{3,  3,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
#else
	{7,  3,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
#endif
	{7,  7,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC3 */
static struct port_params tx_top_mic_4p8MHz[SWR_MSTR_PORT_LEN] = {
#ifndef CONFIG_MACH_XIAOMI
	{3,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
#else
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
#endif
	{15,  3,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* 1 Channel configuration */
/* SWR DMIC0 */
static struct port_params tx_bottom_mic_0p6MHz[SWR_MSTR_PORT_LEN] = {
	{3,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC1 */
static struct port_params tx_receiver_mic_0p6MHz[SWR_MSTR_PORT_LEN] = {
	{3,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC2 */
static struct port_params tx_back_mic_0p6MHz[SWR_MSTR_PORT_LEN] = {
	{3,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

/* SWR DMIC3 */
static struct port_params tx_top_mic_0p6MHz[SWR_MSTR_PORT_LEN] = {
	{3,  3,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
};

struct swr_dev_frame_config {
	struct port_params *pp;
};

static struct swr_dev_frame_config swrdev_frame_params_9p6MHz[] = {
	{tx_dummy},
	{tx_wcd_9p6MHz},
	{tx_top_mic_9p6MHz},
	{tx_back_mic_9p6MHz},
	{tx_receiver_mic_9p6MHz},
	{tx_bottom_mic_9p6MHz},
};

static struct swr_dev_frame_config swrdev_frame_params_4p8MHz[] = {
	{tx_dummy},
	{tx_wcd_4p8MHz},
	{tx_top_mic_4p8MHz},
	{tx_back_mic_4p8MHz},
	{tx_receiver_mic_4p8MHz},
	{tx_bottom_mic_4p8MHz},
};

static struct swr_dev_frame_config swrdev_frame_params_0p6MHz[] = {
	{tx_dummy},
	{tx_wcd_0p6MHz},
	{tx_top_mic_0p6MHz},
	{tx_back_mic_0p6MHz},
	{tx_receiver_mic_0p6MHz},
	{tx_bottom_mic_0p6MHz},
};

#endif /* _LAHAINA_PORT_CONFIG */
