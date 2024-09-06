/*
* Copyright 2023, 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>


#include "lvgl.h"
#include "custom.h"

#include <stdlib.h>


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
BTN_STATUS_T btn_status = kBTN_StatusSTOP;

char current_hrs_str[sizeof(int)*8+1];
char current_sec_str[sizeof(int)*8+1];
char current_min_str[sizeof(int)*8+1];

int current_hrs, current_min, current_sec;
int timer_init = 0;


/**
 * Create a demo application
 */


void my_timer(lv_timer_t * timer)
{
	  char add_zero_hrs[sizeof(int)*8+1] = "0";
	  char add_zero_min[sizeof(int)*8+1] = "0";
	  char add_zero_sec[sizeof(int)*8+1] = "0";


	if(btn_status == kBTN_StatusSTART){
      if((current_hrs == 0) && (current_min == 0) && (current_sec == 0)){
        lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,"00");
        lv_label_set_text(guider_ui.ui_timer_screen_min_label,"00");
        lv_label_set_text(guider_ui.ui_timer_screen_sec_label,"00");
        btn_status = kBTN_StatusIDLE;
      }
      else{

            if((current_min == 0) && (current_sec == 0)){
              current_hrs = current_hrs - 1;
            }
            if(current_sec == 0){
              current_sec = 59;
              if(current_min == 0){
                current_min = 59;
              }
              else{
                current_min = current_min - 1;
              }
            }
            else{
              current_sec = current_sec - 1;
            }

            if((current_min == 0) && (current_sec == 0) && (current_hrs == 0))
            {
            	timer_init = 1;
            }


            itoa(current_hrs,current_hrs_str,10);
            itoa(current_min,current_min_str,10);
            itoa(current_sec,current_sec_str,10);

            if(current_hrs < 10){
              strcat(add_zero_hrs,current_hrs_str);
              lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,add_zero_hrs);//updates the value of the hrs in the label
            }
            if(current_min < 10){
              strcat(add_zero_min,current_min_str);
              lv_label_set_text(guider_ui.ui_timer_screen_min_label,add_zero_min);//updates the value of the min in the label
            }
            if(current_sec < 10){
              strcat(add_zero_sec,current_sec_str);
              lv_label_set_text(guider_ui.ui_timer_screen_sec_label,add_zero_sec);//updates the value of the sec in the label
            }
            if(current_hrs >= 10){
              lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,current_hrs_str);//updates the value of the hrs in the label
            }
            if(current_min >= 10){
              lv_label_set_text(guider_ui.ui_timer_screen_min_label,current_min_str);//updates the value of the min in the label
            }
            if(current_sec >= 10){
              lv_label_set_text(guider_ui.ui_timer_screen_sec_label,current_sec_str);//updates the value of the sec in the label
            }
      }
    }
    else if(btn_status == kBTN_StatusSTOP){
      btn_status = kBTN_StatusIDLE;
    }
    else if(btn_status == kBTN_StatusRESET){
      btn_status = kBTN_StatusIDLE;
    }
    else if(btn_status == kBTN_StatusIDLE){
      btn_status = kBTN_StatusIDLE;
    }

}

void custom_init(lv_ui *ui)
{

  setup_scr_ui_set_timer_screen(&guider_ui);
  guider_ui.ui_set_timer_screen_del = false;

  lv_obj_set_height(guider_ui.ui_set_timer_screen_hrs_roller, 110);
  lv_obj_set_height(guider_ui.ui_set_timer_screen_min_roller, 110);
  lv_obj_set_height(guider_ui.ui_set_timer_screen_sec_roller, 110);

  lv_canvas_fill_bg(guider_ui.ui_set_timer_screen_sec_roller, lv_color_white(), LV_OPA_TRANSP);


  lv_timer_t * timer = lv_timer_create(my_timer, 1000, NULL);
}

