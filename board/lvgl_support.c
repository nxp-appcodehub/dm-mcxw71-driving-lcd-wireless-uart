/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "lvgl_support.h"
#include "lvgl.h"
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#include "semphr.h"
#endif

#include "board.h"
#include "lvgl_support.h"
#include "fsl_gpio.h"
#include "fsl_debug_console.h"
#include "fsl_ft7401.h"
#include "fsl_gt911.h"
#include "fsl_lpspi_cmsis.h"
#include "fsl_lpi2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Port Me, Start. */
#define BOARD_TOUCH_I2C           LPI2C1
#define BOARD_TOUCH_I2C_IRQ       LPI2C1_IRQn
#define BOARD_TOUCH_I2C_FREQ_FUNC LPI2C1_GetFreq
#define BOARD_TOUCH_I2C_FREQ      CLOCK_GetIpFreq(kCLOCK_Lpi2c1)
#define DEMO_I2C_BAUDRATE            400000U

#define BOARD_LCD_SPI           Driver_SPI1
#define BOARD_LCD_SPI_BAUDRATE  32000000U
#define BOARD_LCD_SPI_IRQ       LPSPI1_IRQn
#define BOARD_LCD_SPI_FREQ_FUNC LPSPI1_GetFreq
#define BOARD_LCD_SPI_FREQ      CLOCK_GetIpFreq(kCLOCK_Lpspi1)
// #define BOARD_LCD_SPI_DMA_IRQ   DMA0_IRQn
/* Port Me, End. */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_InitLcd(void);
static void DEMO_InitTouch(void);
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data);
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
/*******************************************************************************
 * Variables
 ******************************************************************************/
static gt911_handle_t touch_handle;
static volatile uint32_t spi_event;
static volatile bool spi_event_received;
#if defined(SDK_OS_FREE_RTOS)
static SemaphoreHandle_t s_transferDone;
#else
static volatile bool s_transferDone;
#endif
SDK_ALIGN(static uint8_t s_frameBuffer[1][LCD_VIRTUAL_BUF_SIZE * LCD_FB_BYTE_PER_PIXEL], 4);
/*******************************************************************************
 * Code
 ******************************************************************************/
void lv_port_pre_init(void)
{
}

uint32_t BOARD_LCD_SPI_FREQ_FUNC(void)
{
    return BOARD_LCD_SPI_FREQ;
}

uint32_t BOARD_TOUCH_I2C_FREQ_FUNC(void)
{
    return BOARD_TOUCH_I2C_FREQ;
}

static void SPI_MasterSignalEvent(uint32_t event)
{
#if defined(SDK_OS_FREE_RTOS)
    BaseType_t taskAwake = pdFALSE;

    xSemaphoreGiveFromISR(s_transferDone, &taskAwake);

    portYIELD_FROM_ISR(taskAwake);
#else
    s_transferDone = true;
#endif
}

static void SPI_WaitEvent(void)
{
#if defined(SDK_OS_FREE_RTOS)
    if (xSemaphoreTake(s_transferDone, portMAX_DELAY) != pdTRUE)
    {
        PRINTF("LCD SPI transfer error\r\n");
    }
#else
    while (false == s_transferDone)
    {
    }
    s_transferDone = false;
#endif
}

static void DEMO_SPI_LCD_WriteCmd(uint8_t Data)
{
    GPIO_PortClear(BOARD_LCD_DC_GPIO, 1u << BOARD_LCD_DC_GPIO_PIN);
    BOARD_LCD_SPI.Send(&Data, 1);
    SPI_WaitEvent();
}

static void DEMO_SPI_LCD_WriteData(uint8_t Data)
{
    GPIO_PortSet(BOARD_LCD_DC_GPIO, 1u << BOARD_LCD_DC_GPIO_PIN);
    BOARD_LCD_SPI.Send(&Data, 1);
    SPI_WaitEvent();
}

static void DEMO_SPI_LCD_WriteMultiData(const uint8_t *pData, int NumItems)
{
    GPIO_PortSet(BOARD_LCD_DC_GPIO, 1u << BOARD_LCD_DC_GPIO_PIN);

    BOARD_LCD_SPI.Send(pData, NumItems);
    SPI_WaitEvent();
}

static void DEMO_InitLcd(void)
{
    /* Enables the clock for GPIO: Enables clock */
    CLOCK_EnableClock(kCLOCK_GpioB);

    /* Define the init structure for the data/command output pin */
    gpio_pin_config_t dc_config = {
        kGPIO_DigitalOutput,
        1,
    };

    /* Init data/command GPIO output . */
    GPIO_PinInit(BOARD_LCD_DC_GPIO, BOARD_LCD_DC_GPIO_PIN, &dc_config);

    CLOCK_SetIpSrc(kCLOCK_Lpspi1, kCLOCK_IpSrcFro192M);
    CLOCK_SetIpSrcDiv(kCLOCK_Lpspi1, kSCG_SysClkDivBy16);

#if defined(SDK_OS_FREE_RTOS)
    s_transferDone = xSemaphoreCreateBinary();
    if (NULL == s_transferDone)
    {
        PRINTF("Semaphore create failed\r\n");
        assert(0);
    }
#else
    s_transferDone = false;
#endif

#if defined(SDK_OS_FREE_RTOS)
    /* FreeRTOS kernel API is used in SPI ISR, so need to set proper IRQ priority. */
    NVIC_SetPriority(BOARD_LCD_SPI_IRQ, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
    // NVIC_SetPriority(BOARD_LCD_SPI_DMA_IRQ, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
#endif

    /* SPI master init */
    BOARD_LCD_SPI.Initialize(SPI_MasterSignalEvent);
    BOARD_LCD_SPI.PowerControl(ARM_POWER_FULL);
    BOARD_LCD_SPI.Control(ARM_SPI_MODE_MASTER, BOARD_LCD_SPI_BAUDRATE);
    FT7401_Init(DEMO_SPI_LCD_WriteData, DEMO_SPI_LCD_WriteCmd);
    /* Change to landscape view. */
    DEMO_SPI_LCD_WriteCmd(0x2C);

}

void lv_port_disp_init(void)
{
    static lv_disp_draw_buf_t disp_buf;

    memset(s_frameBuffer, 0, sizeof(s_frameBuffer));
    lv_disp_draw_buf_init(&disp_buf, s_frameBuffer[0], NULL, LCD_VIRTUAL_BUF_SIZE);

    /*-------------------------
     * Initialize your display
     * -----------------------*/
    DEMO_InitLcd();

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv; /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);   /*Basic initialization*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = DEMO_FlushDisplay;

    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    lv_coord_t x1 = area->x1;
    lv_coord_t y1 = area->y1;
    lv_coord_t x2 = area->x2;
    lv_coord_t y2 = area->y2;

    uint8_t data[4];
    const uint8_t *pdata = (const uint8_t *)color_p;
    uint32_t send_size   = (x2 - x1 + 1) * (y2 - y1 + 1) * LCD_FB_BYTE_PER_PIXEL;

    /*Column addresses*/
    DEMO_SPI_LCD_WriteCmd(FT7401_CMD_COLADDR);
    data[0] = (x1 >> 8) & 0xFF;
    data[1] = x1 & 0xFF;
    data[2] = (x2 >> 8) & 0xFF;
    data[3] = x2 & 0xFF;
    DEMO_SPI_LCD_WriteMultiData(data, 4);

    /*Page addresses*/
    DEMO_SPI_LCD_WriteCmd(FT7401_CMD_PAGEADDR);
    data[0] = (y1 >> 8) & 0xFF;
    data[1] = y1 & 0xFF;
    data[2] = (y2 >> 8) & 0xFF;
    data[3] = y2 & 0xFF;
    DEMO_SPI_LCD_WriteMultiData(data, 4);

    /*Memory write*/
    DEMO_SPI_LCD_WriteCmd(FT7401_CMD_GRAM);
    DEMO_SPI_LCD_WriteMultiData(pdata, send_size);

    lv_disp_flush_ready(disp_drv);
}

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad */
    DEMO_InitTouch();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type    = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = DEMO_ReadTouch;
    lv_indev_drv_register(&indev_drv);
}

static void I2C_MasterSignalEvent(uint32_t event)
{
    /* Notify touch driver about status of the IO operation */
    //FT6X06_EventHandler(&touch_handle, event);
}

/*Initialize your touchpad*/
static void DEMO_InitTouch(void)
{
	  status_t status;

	    /* The FreeRTOS kernel APIs are not used in I2C ISR, so the
	  //    interrupt priority could be set to 0.

	   // NVIC_SetPriority(BOARD_TOUCH_I2C_IRQ, 0);

	  //  attach 12 MHz clock to I2C0
	  // CLOCK_SetIpSrc(kCLOCK_Lpi2c1, kCLOCK_IpSrcFro192M);
	  //  CLOCK_SetIpSrcDiv(kCLOCK_Lpi2c1, kSCG_SysClkDivBy16);

	  //  Init I2C1
	   // BOARD_TOUCH_I2C.Initialize(I2C_MasterSignalEvent);
	  //  BOARD_TOUCH_I2C.PowerControl(ARM_POWER_FULL);
	  //  BOARD_TOUCH_I2C.Control(ARM_I2C_BUS_SPEED, ARM_I2C_BUS_SPEED_FAST);
		*/

	    lpi2c_master_config_t masterConfig;
	    /*
	     * masterConfig.enableMaster = true;
	     * masterConfig.baudRate_Bps = 100000U;
	     * masterConfig.enableTimeout = false;
	     */
	    LPI2C_MasterGetDefaultConfig(&masterConfig);
	    /* Change the default baudrate configuration */
	    masterConfig.baudRate_Hz = DEMO_I2C_BAUDRATE;

	    CLOCK_SetIpSrc(kCLOCK_Lpi2c1, kCLOCK_IpSrcFro192M);
	     CLOCK_SetIpSrcDiv(kCLOCK_Lpi2c1, kSCG_SysClkDivBy16);


	    LPI2C_MasterInit(LPI2C1, &masterConfig, BOARD_TOUCH_I2C_FREQ);
	    /* Initialize the touch handle. */
	    status = GT911_Init(&touch_handle, LPI2C1);

	    if (status != kStatus_Success)
	    {
//	        PRINTF("Touch panel init failed\n");
	        assert(0);
	    }
}

/* Will be called by the library to read the touchpad */
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    touch_event_t touch_event;
    static int touch_x = 0;
    static int touch_y = 0;

    data->state = LV_INDEV_STATE_REL;

    if (kStatus_Success == GT911_GetSingleTouch(&touch_handle, &touch_event, &touch_x, &touch_y))
    {
        if ((touch_event == kTouch_Down) || (touch_event == kTouch_Contact))
        {
            data->state = LV_INDEV_STATE_PR;
        }
    }

    /*Set the last pressed coordinates*/
    data->point.x = 479 - touch_x;
    data->point.y = 319 - touch_y;
}
