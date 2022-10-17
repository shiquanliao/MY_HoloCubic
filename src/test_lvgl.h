#ifndef TEST_LVGL_H
#define TEST_LVGL_H

#include <lvgl.h>

#define DISP_HOR_RES 240
#define DISP_VER_RES 240
/* Maximal horizontal and vertical resolution to support by the library.*/
#define LV_HOR_RES_MAX (240)
#define LV_VER_RES_MAX (240)

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[DISP_HOR_RES * DISP_VER_RES / 10];

#if LV_USE_LOG != 0
/* Serial debugging */
void my_log_cb(const char *buf)
{
    // serial_send(buf, strlen(buf));
}
#endif

static void btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        static uint8_t cnt = 0;
        cnt++;

        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t *label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

void my_print(lv_log_level_t level, const char *file, uint32_t line, const char *fun, const char *dsc)
{
    Serial.printf("%s@%d %s->%s\r\n", file, line, fun, dsc);
    Serial.flush();
}

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft->setAddrWindow(area->x1, area->y1, w, h);
    tft->startWrite();
    // tft->writePixels(&color_p->full, w * h);
    tft->pushColors(&color_p->full, w * h, true);
    tft->endWrite();
    // Initiate DMA - blocking only if last DMA is not complete
    // tft->pushImageDMA(area->x1, area->y1, w, h, bitmap, &color_p->full);

    lv_disp_flush_ready(disp);
}

void test_lvgl_init()
{
    ledcSetup(LCD_BL_PWM_CHANNEL, 5000, 10);
    ledcAttachPin(LCD_BL_PIN, LCD_BL_PWM_CHANNEL);

    lv_init();
#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_log_cb); /* register print function for debugging */
#endif

    ledcWrite(LCD_BL_PWM_CHANNEL, 850);
    // tft init
    tft->init(); // equal tft->begin()
    tft->setRotation(4);
    tft->fillScreen(TFT_ORANGE);

    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, DISP_HOR_RES * DISP_VER_RES / 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); /*Basic initialization for driver */
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    // 开启 LV_COLOR_SCREEN_TRANSP 屏幕具有透明和不透明样式
    lv_disp_drv_register(&disp_drv);
}

/**
 * @brief
 * create a button with a label and react on click event
 */
void test_lvgl_button()
{
    // Add a button the current screen
    lv_obj_t *btn = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(btn, 40, 30);
    lv_obj_set_size(btn, 120, 50);
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    /* Create simple label */
    lv_obj_t *label1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label1, "Hello Arduino!");
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0);
}

#endif