#include "app_controller.h"
#include "app_controller_gui.h"

AppController::AppController()
{
    app_num = 0;
    app_exit_flag = false;
    cur_app_index = 0;
    pre_app_index = 0;
    m_wifi_status = false;
    m_preWifiReqMillis = millis();
    // 设置CPU主频
    setCpuFrequencyMhz(80);
    uint32_t freq = getCpuFrequencyMhz();   // In MHz
    // uint32_t freq = getXtalFrequencyMhz(); // In MHz
    Serial.print(F("getCpuFrequencyMhz: "));
    Serial.println(freq);

    app_controller_gui_init();
    appList[0] = new APP_OBJ();
    // appList[0]->app_image = &app_loading;
    appList[0]->app_image = &bigSon;
    appList[0]->app_name = "None";
    display();
}

void AppController::display()
{
    // appList[0].app_image = &app_loading;
    app_control_display_scr(appList[cur_app_index]->app_image,
                            appList[cur_app_index]->app_name,
                            LV_SCR_LOAD_ANIM_NONE, true);
}