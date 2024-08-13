/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017,2019, 2022, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_ft7401.h"
#define DIR270 1
void FT7401_Init(ft7401_send_byte_t _writeData, ft7401_send_byte_t _writeCommand)
{
    SDK_DelayAtLeastUs(FT7401_RESET_CANCEL_MS * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    _writeCommand(FT7401_CMD_PWRA);
    _writeData(0x39);
    _writeData(0x2C);
    _writeData(0x00);
    _writeData(0x34);
    _writeData(0x02);
    _writeCommand(FT7401_CMD_PWRB);
    _writeData(0x00);
    _writeData(0xC1);
    _writeData(0x30);
    _writeCommand(FT7401_CMD_DTCA);
    _writeData(0x85);
    _writeData(0x00);
    _writeData(0x78);
    _writeCommand(FT7401_CMD_DTCB);
    _writeData(0x00);
    _writeData(0x00);
    _writeCommand(FT7401_CMD_PWRSEQ);
    _writeData(0x64);
    _writeData(0x03);
    _writeData(0x12);
    _writeData(0x81);
    _writeCommand(FT7401_CMD_PRC);
    _writeData(0x20);
    _writeCommand(FT7401_CMD_PWR1);
    _writeData(0x23);
    _writeCommand(FT7401_CMD_PWR2);
    _writeData(0x10);
    _writeCommand(FT7401_CMD_VCOM1);
    _writeData(0x3E);
    _writeData(0x28);
    _writeCommand(FT7401_CMD_VCOM2);
    _writeData(0x86);
    _writeCommand(FT7401_CMD_MAC);
    _writeData(0xE8);//
    _writeCommand(FT7401_CMD_PIXELFORMAT);
    _writeData(0x55);
    _writeCommand(FT7401_CMD_FRC);
    _writeData(0x00);
    _writeData(0x18);
    _writeCommand(FT7401_CMD_DFC);
    _writeData(0x08);
    _writeData(0x82);
    _writeData(0x27);
    _writeCommand(FT7401_CMD_3GAMMAEN);
    _writeData(0x00);
    _writeCommand(FT7401_CMD_COLADDR);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0xEF);
    _writeCommand(FT7401_CMD_PAGEADDR);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x01);
    _writeData(0x3F);
    _writeCommand(FT7401_CMD_GAMMA);
    _writeData(0x01);
    _writeCommand(FT7401_CMD_PGAMMA);
    _writeData(0x0F);
    _writeData(0x31);
    _writeData(0x2B);
    _writeData(0x0C);
    _writeData(0x0E);
    _writeData(0x08);
    _writeData(0x4E);
    _writeData(0xF1);
    _writeData(0x37);
    _writeData(0x07);
    _writeData(0x10);
    _writeData(0x03);
    _writeData(0x0E);
    _writeData(0x09);
    _writeData(0x00);
    _writeCommand(FT7401_CMD_NGAMMA);
    _writeData(0x00);
    _writeData(0x0E);
    _writeData(0x14);
    _writeData(0x03);
    _writeData(0x11);
    _writeData(0x07);
    _writeData(0x31);
    _writeData(0xC1);
    _writeData(0x48);
    _writeData(0x08);
    _writeData(0x0F);
    _writeData(0x0C);
    _writeData(0x31);
    _writeData(0x36);
    _writeData(0x0F);
    _writeCommand(0x21);
    _writeCommand(FT7401_CMD_SLEEPOUT);
    _writeCommand(FT7401_CMD_DISPLAYON);
}

void FT7401_Init1(ft7401_send_cmd_data_t sendCmdData, ft7401_send_byte_t _writeCommand)
{
    SDK_DelayAtLeastUs(FT7401_RESET_CANCEL_MS * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
#if DIR270
    sendCmdData(0xF0, (const uint8_t[]){0xC3U}, 1u);// Enable command part 1
    sendCmdData(0xF0, (const uint8_t[]){0xA6U}, 1u);// Enable command part 2
    sendCmdData(0xB4, (const uint8_t[]){0x01U}, 1u);// Display inversion
    sendCmdData(0xB1, (const uint8_t[]){0x80U, 0x10U}, 2u);// Frame rate control 1
    sendCmdData(0xB5, (const uint8_t[]){0x1FU, 0x50U, 0x00U, 0x20U}, 4u);// Blanking porch control
    sendCmdData(0xB6, (const uint8_t[]){0x8AU, 0x07U, 0x3BU}, 3u);// Display function control
    sendCmdData(0xC0, (const uint8_t[]){0x80U, 0x64U}, 2u);// Power control 1
    sendCmdData(0xC1, (const uint8_t[]){0x13U}, 1u);// Power control 2
    sendCmdData(0xC2, (const uint8_t[]){0xA7U}, 1u);// Power control 3
    sendCmdData(0xC5, (const uint8_t[]){0x09U}, 1u);// VCOM control
    sendCmdData(0xE8, (const uint8_t[]){0x40U, 0x8AU, 0x00U, 0x00U, 0x29U, 0x19U, 0xA5U, 0x33U}, 8u); // DOCA
    sendCmdData(0xE0, (const uint8_t[]){0xF0U, 0x06U, 0x0BU, 0x07U, 0x06U, 0x05U, 0x2EU, 0x33U, 0x47U, 0x3AU, 0x17U, 0x14U, 0x2EU, 0x31U}, 14u);// PGC
    sendCmdData(0xE1, (const uint8_t[]){0xF0U, 0x09U, 0x0DU, 0x09U, 0x08U, 0x23U, 0x2EU, 0x33U, 0x46U, 0x38U, 0x13U, 0x13U, 0x2CU, 0x32U}, 14u);// NGC
    sendCmdData(0xF0, (const uint8_t[]){0xC3U}, 1u);// Disable command part 1
    sendCmdData(0xF0, (const uint8_t[]){0x69U}, 1u);//Disable command part 2

#if WP_LCD
    sendCmdData(0x20, NULL, 0U);//Display invertion ON
#else
    sendCmdData(0x21, NULL, 0U);//Display invertion ON
#endif
    sendCmdData(0x3A, (const uint8_t[]){0x05U}, 1u);//Interface Pixel Format
    sendCmdData(0x36, (const uint8_t[]){0x28U}, 1u);//28  2CMemory Data Access Control
    sendCmdData(0x11, NULL, 0U);//Sleep Out
    sendCmdData(0x29, NULL, 0U);//Display On
    sendCmdData(0x2A, (const uint8_t[]){0x00U, 0x00U, 0x01U, 0xDFU}, 4u);//
    sendCmdData(0x2B, (const uint8_t[]){0x00U, 0x00U, 0x01U, 0x3FU}, 4u);//

#else
    sendCmdData(0xF0, (const uint8_t[]){0xC3U}, 1u);// Enable command part 1
    sendCmdData(0xF0, (const uint8_t[]){0x96U}, 1u);// Enable command part 2
    sendCmdData(0xB4, (const uint8_t[]){0x01U}, 1u);// Display inversion
    sendCmdData(0xB1, (const uint8_t[]){0x80U, 0x10U}, 2u);// Frame rate control 1
    sendCmdData(0xB5, (const uint8_t[]){0x1FU, 0x50U, 0x00U, 0x20U}, 4u);// Blanking porch control
    sendCmdData(0xB6, (const uint8_t[]){0x8AU, 0x07U, 0x3BU}, 3u);// Display function control
    sendCmdData(0xC0, (const uint8_t[]){0x80U, 0x64U}, 2u);// Power control 1
    sendCmdData(0xC1, (const uint8_t[]){0x13U}, 1u);// Power control 2
    sendCmdData(0xC2, (const uint8_t[]){0xA7U}, 1u);// Power control 3
    sendCmdData(0xC5, (const uint8_t[]){0x09U}, 1u);// VCOM control
    sendCmdData(0xE8, (const uint8_t[]){0x40U, 0x8AU, 0x00U, 0x00U, 0x29U, 0x19U, 0xA5U, 0x33U}, 8u); // DOCA
    sendCmdData(0xE0, (const uint8_t[]){0xF0U, 0x06U, 0x0BU, 0x07U, 0x06U, 0x05U, 0x2EU, 0x33U, 0x47U, 0x3AU, 0x17U, 0x14U, 0x2EU, 0x31U}, 14u);// PGC
    sendCmdData(0xE1, (const uint8_t[]){0xF0U, 0x09U, 0x0DU, 0x09U, 0x08U, 0x23U, 0x2EU, 0x33U, 0x46U, 0x38U, 0x13U, 0x13U, 0x2CU, 0x32U}, 14u);// NGC
    sendCmdData(0xF0, (const uint8_t[]){0xC3U}, 1u);// Disable command part 1
    sendCmdData(0xF0, (const uint8_t[]){0x69U}, 1u);//Disable command part 2

    sendCmdData(0x21, NULL, 0U);//Display invertion ON
    sendCmdData(0x3A, (const uint8_t[]){0x05U}, 1u);//Interface Pixel Format
    sendCmdData(0x36, (const uint8_t[]){0xE8U}, 1u);//Memory Data Access Control
    sendCmdData(0x11, NULL, 0U);//Sleep Out
    sendCmdData(0x29, NULL, 0U);//Display On
    sendCmdData(0x2A, (const uint8_t[]){0x00U, 0x00U, 0x01U, 0xDFU}, 4u);//
    sendCmdData(0x2B, (const uint8_t[]){0x00U, 0x00U, 0x01U, 0x3FU}, 4u);//
    //sendCmdData(0x2C, NULL, 0U);
#endif
}
