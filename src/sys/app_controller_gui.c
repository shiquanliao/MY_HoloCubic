#include "app_controller_gui.h"

// 必须定义为全局或者静态
static lv_obj_t *app_scr = NULL;
static lv_obj_t *pre_app_name = NULL;
static lv_obj_t *pre_app_image = NULL;
static lv_obj_t *now_app_name = NULL;
static lv_obj_t *now_app_image = NULL;
static lv_obj_t *pre_img_path = NULL;

// static lv_group_t *g;
static lv_style_t defalut_state_style;
static lv_style_t pressed_state_style;
static lv_style_t focused_state_style;

static lv_style_t app_name_style;

LV_FONT_DECLARE(lv_font_montserrat_24);
LV_FONT_DECLARE(lv_font_cn_test_zhongguo_30);

void app_controller_gui_init(void)
{
    if (NULL != app_scr)
    {
        lv_obj_clean(app_scr);
        app_scr = NULL;
    }

    lv_style_init(&defalut_state_style);
    lv_style_set_bg_color(&defalut_state_style, lv_color_black());

    lv_style_init(&pressed_state_style);
    lv_style_set_bg_color(&pressed_state_style, lv_color_black());

    lv_style_init(&app_name_style);
    lv_style_set_text_opa(&app_name_style, LV_OPA_COVER);
    lv_style_set_text_color(&app_name_style, lv_color_hex(0xeddd00));
    lv_style_set_text_font(&app_name_style, &lv_font_cn_test_zhongguo_30);

    // APP 图标页
    app_scr = lv_obj_create(NULL);
    lv_obj_add_style(app_scr, &defalut_state_style, LV_STATE_DEFAULT);
}

void app_controller_gui_release(void)
{
    if (NULL != app_scr)
    {
        lv_obj_clean(app_scr);
        app_scr = NULL;
    }
}

void display_app_scr_init(const void *scr_img_path, const char *app_name)
{
    lv_obj_t *act_obj = lv_scr_act();
    if (act_obj == app_scr)
    {
        // 防止一些不适用lvgl的APP退出 造成画面在无其他动作情况下无法绘制更新
        lv_scr_load_anim(app_scr, LV_SCR_LOAD_ANIM_NONE, 300, 300, false);
        return;
    }
    
   
    lv_obj_clean(act_obj);                  // 清空此前页面
    pre_app_image = lv_img_create(app_scr); // 设置为上次的app
    lv_img_set_src(pre_app_image, scr_img_path);
    pre_img_path = scr_img_path;
    
   
    lv_obj_align(pre_app_image, LV_ALIGN_CENTER, 0, -20);

    // // 添加APP的名字
    pre_app_name = lv_label_create(app_scr);
    lv_obj_add_style(pre_app_name, &app_name_style, LV_STATE_DEFAULT);
    lv_label_set_text(pre_app_name, app_name);
    lv_obj_align(pre_app_name, LV_ALIGN_CENTER, 0, 10);
   

    lv_scr_load_anim(app_scr, LV_SCR_LOAD_ANIM_NONE, 300, 300, false);
}

void app_control_display_scr(const void *scr_img, const char *app_name, lv_scr_load_anim_t anim_style, bool force)
{
    // force Indicates whether to forcibly refresh the page. true Indicates that the page is forcibly refreshed
    if (true == force)
    {
        display_app_scr_init(scr_img, app_name);
        return;
    }

    if (scr_img == pre_app_image)
    {
        return;
    }

    pre_img_path = scr_img;
    int now_start_x;
    int now_end_x;
    int old_start_x;
    int old_end_x;

    if (LV_SCR_LOAD_ANIM_MOVE_LEFT == anim_style)
    {
        // 向左移出
        now_start_x = -128;
        now_end_x = 56;
        old_start_x = 56;
        old_end_x = 240;
    }
    else
    {
        now_start_x = 240;
        now_end_x = 56;
        old_start_x = 56;
        old_end_x = -128;
    }

    // 添加图片
    now_app_image = lv_img_create(app_scr);
    lv_img_set_src(now_app_image, scr_img);
    lv_obj_align(now_app_image, LV_ALIGN_CENTER, 0, -20);

    // 添加名字
    now_app_name = lv_label_create(app_scr);
    lv_obj_add_style(now_app_image, &app_name_style, LV_STATE_DEFAULT);
    lv_label_set_text(now_app_name, app_name);

    // 删除原先的APP name
    lv_obj_del(pre_app_name);
    pre_app_image = now_app_image;
    lv_obj_align(now_app_image, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

    // todo animation

    lv_obj_del(pre_app_image); // 删除原先的图像
    pre_app_image = now_app_image;
}