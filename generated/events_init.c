/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


#include "custom.h"
extern BTN_STATUS_T btn_status;
#include <stdio.h>
#include <stdlib.h>
#include <custom.h>

extern int current_hrs, current_min, current_sec;

//The itoa() and strcat() functions specifies that the minimum size of the array must be sizeof(int)*8+1
char hrs_str[sizeof(int)*8+1]; //to have the current hrs in ascii
char min_str[sizeof(int)*8+1]; //to have the current min in ascii
char sec_str[sizeof(int)*8+1]; //to have the current sec in ascii

int set_btn = 0;
int reset_btn = 0;
int start_btn = 0;
int stop_btn = 0;
int set_date_btn = 0;
int set_timer_btn = 0;


uint8_t current_timer_ble[10];
uint8_t current_date_ble[20];

static void ui_timer_screen_start_stop_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		if((btn_status == kBTN_StatusSTOP) || (btn_status == kBTN_StatusIDLE)){
	  btn_status = kBTN_StatusSTART;
	  start_btn = 1;
	  stop_btn = 0;
	  set_btn = 0;
	  reset_btn = 0;
	  set_date_btn = 0;
	  set_timer_btn = 0;
	}
	else{
	  btn_status = kBTN_StatusSTOP;
	  stop_btn = 1;
	  start_btn = 0;
	  set_btn = 0;
	  reset_btn = 0;
	  set_date_btn = 0;
	  set_timer_btn = 0;
	}
		break;
	}
	default:
		break;
	}
}
static void ui_timer_screen_reset_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_hrs_roller, hrs_str, 0);
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_min_roller, min_str, 0);
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_sec_roller, sec_str, 0);
	
	current_hrs = atoi(hrs_str);
	current_min = atoi(min_str);
	current_sec = atoi(sec_str);
	

	lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,hrs_str);//updates the value of the hrs in the label
	lv_label_set_text(guider_ui.ui_timer_screen_min_label,min_str);//updates the value of the min in the label
	lv_label_set_text(guider_ui.ui_timer_screen_sec_label,sec_str);//updates the value of the sec in the label
	
	btn_status = kBTN_StatusRESET;

	  start_btn = 0;
	  stop_btn = 0;
	  set_btn = 0;
	  reset_btn = 1;
	  set_date_btn = 0;
	  set_timer_btn = 0;

		break;
	}
	default:
		break;
	}
}
static void ui_timer_screen_set_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.ui_set_timer_screen, guider_ui.ui_set_timer_screen_del, &guider_ui.ui_timer_screen_del, setup_scr_ui_set_timer_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
		  start_btn = 0;
		  stop_btn = 0;
		  set_btn = 1;
		  reset_btn = 0;
		  set_date_btn = 0;
		  set_timer_btn = 0;

		break;
	}
	default:
		break;
	}
}
void events_init_ui_timer_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_timer_screen_start_stop_btn, ui_timer_screen_start_stop_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_timer_screen_reset_btn, ui_timer_screen_reset_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_timer_screen_set_btn, ui_timer_screen_set_btn_event_handler, LV_EVENT_ALL, ui);
}
static void ui_set_timer_screen_set_timer_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		
	
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_hrs_roller, hrs_str, 0);
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_min_roller, min_str, 0);
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_sec_roller, sec_str, 0);
	
	current_hrs = atoi(hrs_str);
	current_min = atoi(min_str);
	current_sec = atoi(sec_str);
	
	 current_timer_ble[0]=  (uint8_t)((current_hrs/10) + 0x30);
	 current_timer_ble[1]= (uint8_t)((current_hrs%10) + 0x30);
	 current_timer_ble[2]=  (uint8_t)((current_min/10) + 0x30);
	 current_timer_ble[3]=  (uint8_t)((current_min%10) + 0x30);
	 current_timer_ble[4]= (uint8_t)((current_sec/10) + 0x30);
	 current_timer_ble[5]=  (uint8_t)((current_sec%10) + 0x30);


	lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,hrs_str);//updates the value of the hrs in the label
	lv_label_set_text(guider_ui.ui_timer_screen_min_label,min_str);//updates the value of the min in the label
	lv_label_set_text(guider_ui.ui_timer_screen_sec_label,sec_str);//updates the value of the sec in the label
	
	
	ui_load_scr_animation(&guider_ui, &guider_ui.ui_timer_screen, guider_ui.ui_set_timer_screen_del, &guider_ui.ui_timer_screen_del, setup_scr_ui_set_timer_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
	
	btn_status = kBTN_StatusIDLE;

	  start_btn = 0;
	  stop_btn = 0;
	  set_btn = 0;
	  reset_btn = 0;
	  set_date_btn = 0;
	  set_timer_btn = 1;

		break;
	}
	default:
		break;
	}
}
static void ui_set_timer_screen_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		char * date_str;
	
	date_str = lv_label_get_text(guider_ui.ui_set_timer_screen_datetext_1);
	
	lv_label_set_text(guider_ui.ui_timer_screen_date_label,date_str);
	
	current_date_ble[0] = date_str[0];
	current_date_ble[1] = date_str[1];
	current_date_ble[2] = date_str[2];
	current_date_ble[3] = date_str[3];

	current_date_ble[5] = date_str[5];
	current_date_ble[6] = date_str[6];

	current_date_ble[8] = date_str[8];
	current_date_ble[9] = date_str[9];
	
	ui_load_scr_animation(&guider_ui, &guider_ui.ui_timer_screen, guider_ui.ui_set_timer_screen_del, &guider_ui.ui_timer_screen_del, setup_scr_ui_set_timer_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
	
	btn_status = kBTN_StatusIDLE;

	  start_btn = 0;
	  stop_btn = 0;
	  set_btn = 0;
	  reset_btn = 0;
	  set_date_btn = 1;
	  set_timer_btn = 0;

		break;
	}
	default:
		break;
	}
}
void events_init_ui_set_timer_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_set_timer_screen_set_timer_btn, ui_set_timer_screen_set_timer_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_set_timer_screen_btn_1, ui_set_timer_screen_btn_1_event_handler, LV_EVENT_ALL, ui);

}

void events_init(lv_ui *ui)
{

}
