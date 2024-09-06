/*
 * Copyright 2019 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _RTE_DEVICE_H
#define _RTE_DEVICE_H

extern void BOARD_InitPins_SPI0();
extern void BOARD_DeInitPins_SPI0();


extern void I2C0_InitPins();
extern void I2C0_DeinitPins();

/*Driver name mapping*/
/* User needs to provide the implementation of SPIX_GetFreq/SPIX_InitPins/SPIX_DeinitPins for the enabled SPI instance.
 */
#define RTE_SPI1            1
#define RTE_SPI1_PIN_INIT   BOARD_InitPins_SPI0
#define RTE_SPI1_PIN_DEINIT BOARD_DeInitPins_SPI0
#define RTE_SPI1_DMA_EN     1

/* SPI configuration. */
#define RTE_SPI1_SLAVE_PCS_PIN_SEL  kLPSPI_Pcs1

/* SPI DMA configuration */
#if RTE_SPI1_DMA_EN
#define RTE_SPI1_PIN_INIT        BOARD_InitPins_SPI0
#define RTE_SPI1_PIN_DEINIT      BOARD_DeInitPins_SPI0
#define RTE_SPI1_DMA_RX_CH       0
#define RTE_SPI1_DMA_RX_DMA_BASE DMA0
#define RTE_SPI1_DMA_TX_CH       1
#define RTE_SPI1_DMA_TX_DMA_BASE DMA0

#endif

/* User needs to provide the implementation of I2CX_GetFreq/I2CX_InitPins/I2CX_DeinitPins for the enabled I2C instance.
 */
#define RTE_I2C1            1
#define RTE_I2C1_PIN_INIT   I2C0_InitPins
#define RTE_I2C1_PIN_DEINIT I2C0_DeinitPins
#define RTE_I2C1_DMA_EN     0

#endif /* _RTE_DEVICE_H */
