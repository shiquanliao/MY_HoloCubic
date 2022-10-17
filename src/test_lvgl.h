#ifndef TEST_LVGL_H
#define TEST_LVGL_H

#include <lvgl.h>

#define DISP_HOR_RES 240
#define DISP_VER_RES 240

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[DISP_HOR_RES * DISP_VER_RES / 10];



void test_lvgl_init()
{
    lv_tick_inc(5);
    lv_init();
}

#endif