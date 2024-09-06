/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2019-2020, 2022, 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_FT7401_H_
#define _FSL_FT7401_H_

#include "fsl_common.h"

/*
 * Change log:
 *
 *   1.0.2
 *     - Add FT9341_Init1.
 *
 *   1.0.1
 *     - Fix MISRA 2012 issues.
 *
 *   1.0.0
 *     - Initial version
 */

/*!
 * @addtogroup ili9341
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Register defines */
#define FT7401_CMD_RST          0x01
#define FT7401_CMD_SLEEPOUT     0x11
#define FT7401_CMD_GAMMA        0x26
#define ILI9341_CMD_DISPLAYOFF   0x28
#define FT7401_CMD_DISPLAYON    0x29
#define FT7401_CMD_COLADDR      0x2A
#define FT7401_CMD_PAGEADDR     0x2B
#define FT7401_CMD_GRAM         0x2C
#define FT7401_CMD_MAC          0x36
#define FT7401_CMD_PIXELFORMAT  0x3A
#define FT7401_CMD_WDB          0x51
#define FT7401_CMD_WCD          0x53
#define FT7401_CMD_RGBINTERFACE 0xB0
#define FT7401_CMD_FRC          0xB1
#define FT7401_CMD_BPC          0xB5
#define FT7401_CMD_DFC          0xB6
#define FT7401_CMD_PWR1         0xC0
#define FT7401_CMD_PWR2         0xC1
#define FT7401_CMD_VCOM1        0xC5
#define FT7401_CMD_VCOM2        0xC7
#define FT7401_CMD_PWRA         0xCB
#define FT7401_CMD_PWRB         0xCF
#define FT7401_CMD_PGAMMA       0xE0
#define FT7401_CMD_NGAMMA       0xE1
#define FT7401_CMD_DTCA         0xE8
#define FT7401_CMD_DTCB         0xEA
#define FT7401_CMD_PWRSEQ       0xED
#define FT7401_CMD_3GAMMAEN     0xF2
#define FT7401_CMD_INTERFACE    0xF6
#define FT7401_CMD_PRC          0xF7
#define FT7401_CMD_INVON        0x21
#define FT7401_CMD_INVOFF       0x20

/* 120ms is necessary after reset, for loading ID bytes, VCOM setting,
 * and other settings from NV memory to registers.
 */
#define FT7401_RESET_CANCEL_MS 120U

typedef void (*ft7401_send_byte_t)(uint8_t dataToSend);
typedef void (*ft7401_send_cmd_data_t)(uint8_t cmd, const uint8_t *data, uint32_t dataLen);

void FT7401_Init(ft7401_send_byte_t _writeData, ft7401_send_byte_t _writeCommand);

void FT7401_Init1(ft7401_send_cmd_data_t sendCmdData, ft7401_send_byte_t _writeCommand);

#endif
