#include "display.h"
#include "common.h"
#include "lv_conf.h"
#include "lvgl.h"

/* Maximal horizontal and vertical resolution to support by the library.*/
#define LV_HOR_RES_MAX (240)
#define LV_VER_RES_MAX (240)

/* A static or global variable to store the buffers */
static lv_disp_draw_buf_t draw_buf;

/* Static or global buffer(s). The second buffer is optional */
static lv_color_t buf1[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10];

#if LV_USE_LOG != 0
static void my_log_cb(const char *buf)
{
    Serial.printf("Display lvgl: %s", buf);
}
#endif

static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    Serial.println("my_disp_flush be called");
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

void Display::init()
{
    /* attac pin */
    ledcSetup(LCD_BL_PWM_CHANNEL, 5000, 10);
    ledcAttachPin(LCD_BL_PIN, LCD_BL_PWM_CHANNEL);
    // ledcWrite(LCD_BL_PWM_CHANNEL, 850); // 设置PWM 空占比 调整亮度
    setBackLight(0.05);

    /* tft init */
    tft->begin();
    tft->setRotation(4);
    tft->fillScreen(TFT_ORANGE);

    /* lvgl init */
    lv_init();
#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_log_cb);
#endif
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX / 10);

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

void Display::routine()
{
    lv_task_handler();
}

void Display::setBackLight(float duty)
{
    duty = constrain(duty, 0, 1);
    duty = 1 - duty;
    ledcWrite(LCD_BL_PWM_CHANNEL, (int)(duty * 1024));
}