/*! *********************************************************************************
 * \addtogroup Main
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright 2021-2023, 2024 NXP
*
*
* \file
*
* This is the source file for the main entry point for a bare-metal application.
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

/************************************************************************************
 *************************************************************************************
 * Include
 *************************************************************************************
 ************************************************************************************/
#include "app.h"
#include "app_conn.h"
#include "fsl_os_abstraction.h"

#include "lvgl.h"
#include "lvgl_support.h"
#include "gui_guider.h"
#include "custom.h"
#include"events_init.h"
#include "pin_mux.h"

#if defined(gAppLowpowerEnabled_d) && (gAppLowpowerEnabled_d > 0)
#include "PWR_Interface.h"
#endif

/* 1 ms per tick. */
#ifndef LVGL_TICK_MS
#define LVGL_TICK_MS 1U
#endif

/* lv_task_handler is called every 5-tick. */
#ifndef LVGL_TASK_PERIOD_TICK
#define LVGL_TASK_PERIOD_TICK 5U
#endif

static void DEMO_SetupTick(void);
#if LV_USE_LOG
static void print_cb(const char *buf);
#endif
static volatile uint32_t s_tick        = 0U;
static volatile bool s_lvglTaskPending = false;

lv_ui guider_ui;
/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/
int main(void)
{
    /* Init OSA: should be called before any other OSA API */
    OSA_Init();

    BOARD_InitHardware();
    CLOCK_EnableClock(kCLOCK_Dma0);
    BOARD_InitPins_SPI0();
    I2C0_InitPins();
    DEMO_SetupTick();

#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif

    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();

   lv_port_indev_init();
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);


    /* Start Application services (timers, serial manager, low power, led, button, etc..) */
    APP_InitServices();

    /* Start BLE Platform related ressources such as clocks, Link layer and HCI transport to Link Layer */
    (void)APP_InitBle();

    /* Example of baremetal loop if user doesn't want to use OSA API */
#if (FSL_OSA_BM_TIMER_CONFIG != FSL_OSA_BM_TIMER_NONE)
    OSA_TimeInit();
#endif

    /* Start Host stack */
    BluetoothLEHost_AppInit();




    while(TRUE)
    {
        OSA_ProcessTasks();
        BluetoothLEHost_HandleMessages();

        /* Before executing WFI, need to execute some connectivity background tasks
            (usually done in Idle thread) such as NVM save in Idle, etc.. */
        BluetoothLEHost_ProcessIdleTask();

        OSA_DisableIRQGlobal();

        /* Check if some connectivity tasks have turned to ready state from interrupts or
              if messages are to be processed in Application process */
        if (( OSA_TaskShouldYield() == FALSE ) && ( BluetoothLEHost_IsMessagePending() == FALSE ) && (BluetoothLEHost_IsConnectivityTaskToProcess() == FALSE))
        {
#if defined(gAppLowpowerEnabled_d) && (gAppLowpowerEnabled_d > 0)
            (void)PWR_EnterLowPower(0U);
#else
            __WFI();
#endif
        }


        OSA_EnableIRQGlobal();
        while (!s_lvglTaskPending)
        {
        }
        s_lvglTaskPending = false;

        lv_task_handler();
    }

    /* Won't run here */
    assert(0);
    return 0;
}



static void DEMO_SetupTick(void)
{
    if (0 != SysTick_Config(SystemCoreClock / (LVGL_TICK_MS * 1000U)))
    {
      //  PRINTF("Tick initialization failed\r\n");
        while (1)
            ;
    }
}

void SysTick_Handler(void)
{
    s_tick++;
    lv_tick_inc(LVGL_TICK_MS);

    if ((s_tick % LVGL_TASK_PERIOD_TICK) == 0U)
    {
        s_lvglTaskPending = true;
    }
}
/*! *********************************************************************************
 * @}
 ********************************************************************************** */
