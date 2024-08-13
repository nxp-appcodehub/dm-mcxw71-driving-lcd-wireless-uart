/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_ui_set_timer_screen(lv_ui *ui)
{
	//Write codes ui_set_timer_screen
	ui->ui_set_timer_screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->ui_set_timer_screen, 480, 320);
	lv_obj_set_scrollbar_mode(ui->ui_set_timer_screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_set_timer_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_min_roller
	ui->ui_set_timer_screen_min_roller = lv_roller_create(ui->ui_set_timer_screen);
	lv_roller_set_options(ui->ui_set_timer_screen_min_roller, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59", LV_ROLLER_MODE_NORMAL);
	lv_obj_set_pos(ui->ui_set_timer_screen_min_roller, 86, 73);
	lv_obj_set_width(ui->ui_set_timer_screen_min_roller, 100);

	//Write style for ui_set_timer_screen_min_roller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->ui_set_timer_screen_min_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_min_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_min_roller, lv_color_hex(0x959595), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_min_roller, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_min_roller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_min_roller, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_min_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_min_roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_min_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_min_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_min_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_min_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_set_timer_screen_min_roller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_min_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_min_roller, lv_color_hex(0x000000), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_min_roller, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_min_roller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_min_roller, &lv_font_Adventpro_regular_30, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_min_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_min_roller, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->ui_set_timer_screen_min_roller, 3);
	//Write codes ui_set_timer_screen_hrs_roller
	ui->ui_set_timer_screen_hrs_roller = lv_roller_create(ui->ui_set_timer_screen);
	lv_roller_set_options(ui->ui_set_timer_screen_hrs_roller, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12", LV_ROLLER_MODE_NORMAL);
	lv_obj_set_pos(ui->ui_set_timer_screen_hrs_roller, 21, 73);
	lv_obj_set_width(ui->ui_set_timer_screen_hrs_roller, 47);

	//Write style for ui_set_timer_screen_hrs_roller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_hrs_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_hrs_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_hrs_roller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_hrs_roller, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_hrs_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_hrs_roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_hrs_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_hrs_roller, lv_color_hex(0x959595), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_hrs_roller, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_hrs_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_hrs_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_hrs_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_set_timer_screen_hrs_roller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_hrs_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_hrs_roller, lv_color_hex(0x000000), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_hrs_roller, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_hrs_roller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_hrs_roller, &lv_font_Adventpro_regular_30, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_hrs_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_hrs_roller, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->ui_set_timer_screen_hrs_roller, 3);
	//Write codes ui_set_timer_screen_sec_roller
	ui->ui_set_timer_screen_sec_roller = lv_roller_create(ui->ui_set_timer_screen);
	lv_roller_set_options(ui->ui_set_timer_screen_sec_roller, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59", LV_ROLLER_MODE_NORMAL);
	lv_obj_set_pos(ui->ui_set_timer_screen_sec_roller, 206, 73);
	lv_obj_set_width(ui->ui_set_timer_screen_sec_roller, 100);

	//Write style for ui_set_timer_screen_sec_roller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_sec_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_sec_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_sec_roller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_sec_roller, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_sec_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_sec_roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_sec_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_sec_roller, lv_color_hex(0x959595), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_sec_roller, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_sec_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_sec_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_sec_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_set_timer_screen_sec_roller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_sec_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_sec_roller, lv_color_hex(0x000000), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_sec_roller, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_sec_roller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_sec_roller, &lv_font_Adventpro_regular_30, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_sec_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_sec_roller, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->ui_set_timer_screen_sec_roller, 3);
	//Write codes ui_set_timer_screen_label_1
	ui->ui_set_timer_screen_label_1 = lv_label_create(ui->ui_set_timer_screen);
	lv_label_set_text(ui->ui_set_timer_screen_label_1, ":");
	lv_label_set_long_mode(ui->ui_set_timer_screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_set_timer_screen_label_1, 68, 106);
	lv_obj_set_size(ui->ui_set_timer_screen_label_1, 18, 28);

	//Write style for ui_set_timer_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_label_1, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_set_timer_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_label_2
	ui->ui_set_timer_screen_label_2 = lv_label_create(ui->ui_set_timer_screen);
	lv_label_set_text(ui->ui_set_timer_screen_label_2, ":");
	lv_label_set_long_mode(ui->ui_set_timer_screen_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_set_timer_screen_label_2, 187, 104);
	lv_obj_set_size(ui->ui_set_timer_screen_label_2, 18, 28);

	//Write style for ui_set_timer_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_label_2, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_set_timer_screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_label_3
	ui->ui_set_timer_screen_label_3 = lv_label_create(ui->ui_set_timer_screen);
	lv_label_set_text(ui->ui_set_timer_screen_label_3, "Hrs");
	lv_label_set_long_mode(ui->ui_set_timer_screen_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_set_timer_screen_label_3, 8, 46);
	lv_obj_set_size(ui->ui_set_timer_screen_label_3, 72, 17);

	//Write style for ui_set_timer_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_set_timer_screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_label_4
	ui->ui_set_timer_screen_label_4 = lv_label_create(ui->ui_set_timer_screen);
	lv_label_set_text(ui->ui_set_timer_screen_label_4, "Min");
	lv_label_set_long_mode(ui->ui_set_timer_screen_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_set_timer_screen_label_4, 100, 46);
	lv_obj_set_size(ui->ui_set_timer_screen_label_4, 72, 17);

	//Write style for ui_set_timer_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_set_timer_screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_label_5
	ui->ui_set_timer_screen_label_5 = lv_label_create(ui->ui_set_timer_screen);
	lv_label_set_text(ui->ui_set_timer_screen_label_5, "Sec");
	lv_label_set_long_mode(ui->ui_set_timer_screen_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_set_timer_screen_label_5, 219, 46);
	lv_obj_set_size(ui->ui_set_timer_screen_label_5, 72, 17);

	//Write style for ui_set_timer_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_set_timer_screen_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_set_timer_btn
	ui->ui_set_timer_screen_set_timer_btn = lv_btn_create(ui->ui_set_timer_screen);
	ui->ui_set_timer_screen_set_timer_btn_label = lv_label_create(ui->ui_set_timer_screen_set_timer_btn);
	lv_label_set_text(ui->ui_set_timer_screen_set_timer_btn_label, "SET TIMER");
	lv_label_set_long_mode(ui->ui_set_timer_screen_set_timer_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_set_timer_screen_set_timer_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_set_timer_screen_set_timer_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ui_set_timer_screen_set_timer_btn_label, LV_PCT(100));
	lv_obj_set_pos(ui->ui_set_timer_screen_set_timer_btn, 21, 232);
	lv_obj_set_size(ui->ui_set_timer_screen_set_timer_btn, 285, 50);

	//Write style for ui_set_timer_screen_set_timer_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_set_timer_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_set_timer_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_set_timer_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_set_timer_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_set_timer_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_set_timer_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_set_timer_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_set_timer_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_set_timer_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_set_timer_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_datetext_1
	ui->ui_set_timer_screen_datetext_1 = lv_label_create(ui->ui_set_timer_screen);
	lv_label_set_text(ui->ui_set_timer_screen_datetext_1, "2023/07/31");
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_flag(ui->ui_set_timer_screen_datetext_1, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(ui->ui_set_timer_screen_datetext_1, ui_set_timer_screen_datetext_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->ui_set_timer_screen_datetext_1, 336, 73);
	lv_obj_set_size(ui->ui_set_timer_screen_datetext_1, 130, 36);

	//Write style for ui_set_timer_screen_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_datetext_1, lv_color_hex(0x959595), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_datetext_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_datetext_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_datetext_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_set_timer_screen_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_set_timer_screen_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_set_timer_screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_set_timer_screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_btn_1
	ui->ui_set_timer_screen_btn_1 = lv_btn_create(ui->ui_set_timer_screen);
	ui->ui_set_timer_screen_btn_1_label = lv_label_create(ui->ui_set_timer_screen_btn_1);
	lv_label_set_text(ui->ui_set_timer_screen_btn_1_label, "SET DATE");
	lv_label_set_long_mode(ui->ui_set_timer_screen_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_set_timer_screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_set_timer_screen_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ui_set_timer_screen_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->ui_set_timer_screen_btn_1, 336, 232);
	lv_obj_set_size(ui->ui_set_timer_screen_btn_1, 130, 50);

	//Write style for ui_set_timer_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_set_timer_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_set_timer_screen_btn_1, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_set_timer_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_set_timer_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_set_timer_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_set_timer_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_set_timer_screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_set_timer_screen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_set_timer_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_set_timer_screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_line_1
	ui->ui_set_timer_screen_line_1 = lv_line_create(ui->ui_set_timer_screen);
	static lv_point_t ui_set_timer_screen_line_1[] ={{0, 0},{31, 0},};
	lv_line_set_points(ui->ui_set_timer_screen_line_1, ui_set_timer_screen_line_1, 2);
	lv_obj_set_pos(ui->ui_set_timer_screen_line_1, 28, 140);
	lv_obj_set_size(ui->ui_set_timer_screen_line_1, 35, 2);

	//Write style for ui_set_timer_screen_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_set_timer_screen_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_set_timer_screen_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_set_timer_screen_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_set_timer_screen_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_line_2
	ui->ui_set_timer_screen_line_2 = lv_line_create(ui->ui_set_timer_screen);
	static lv_point_t ui_set_timer_screen_line_2[] ={{0, 0},{31, 0},};
	lv_line_set_points(ui->ui_set_timer_screen_line_2, ui_set_timer_screen_line_2, 2);
	lv_obj_set_pos(ui->ui_set_timer_screen_line_2, 121, 140);
	lv_obj_set_size(ui->ui_set_timer_screen_line_2, 35, 2);

	//Write style for ui_set_timer_screen_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_set_timer_screen_line_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_set_timer_screen_line_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_set_timer_screen_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_set_timer_screen_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_set_timer_screen_line_3
	ui->ui_set_timer_screen_line_3 = lv_line_create(ui->ui_set_timer_screen);
	static lv_point_t ui_set_timer_screen_line_3[] ={{0, 0},{31, 0},};
	lv_line_set_points(ui->ui_set_timer_screen_line_3, ui_set_timer_screen_line_3, 2);
	lv_obj_set_pos(ui->ui_set_timer_screen_line_3, 241, 140);
	lv_obj_set_size(ui->ui_set_timer_screen_line_3, 35, 2);

	//Write style for ui_set_timer_screen_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_set_timer_screen_line_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_set_timer_screen_line_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_set_timer_screen_line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_set_timer_screen_line_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of ui_set_timer_screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->ui_set_timer_screen);

	//Init events for screen.
	events_init_ui_set_timer_screen(ui);
}
