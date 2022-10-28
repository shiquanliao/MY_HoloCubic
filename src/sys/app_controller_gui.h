#ifndef APP_CONTROLLER__GUI_H
#define APP_CONTROLLER__GUI_H


#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
#define ANIEND                      \
    while (lv_anim_count_running()) \
        lv_task_handler();  // 等待动画完成

    void app_controller_gui_init(void);
    void app_controller_gui_release(void);
    void app_controller_scr_release(void);
    void display_app_scr_init(const void* scr_img, const char* app_name);
    void app_control_display_scr(const void* scr_img, const char* app_name,
                                 lv_scr_load_anim_t anim_type, bool force);

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
    extern const lv_img_dsc_t app_loading;
    
#ifdef __cplusplus
} /* extern "C" */
#endif


#endif