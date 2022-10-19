#include "config.h"
#include "common.h"

void config_read(const char *file_path, Config *cfg)
{
    // open namespace
    prefs.begin("Config");
    cfg->ssid = prefs.getString("ssid", "gongzhu");
    cfg->password = prefs.getString("password", "12345678");
    cfg->cityname = prefs.getString("cityname", "shenzhen");
    cfg->language = prefs.getString("language", "zh-Hans");
    cfg->weather_key = prefs.getString("weather_key", "");
    cfg->tianqi_appid = prefs.getString("tianqi_aid", "");
    cfg->tianqi_appsecret = prefs.getString("tianqi_as", "");
    cfg->backLight = prefs.getUChar("backLight", 80);
    cfg->rotation = prefs.getUChar("rotation", 4);
    cfg->auto_calibration_mpu = prefs.getUChar("auto_mpu", 1);

    prefs.end();

    // 读取mup的校准数据 todo
    // mpu_config_read(file_path, cfg);
}

void config_save(const char *file_path, Config *cfg)
{
    prefs.begin("Config");
    prefs.putString("ssid", cfg->ssid);
    prefs.putString("password", cfg->password);
    prefs.putString("cityname", cfg->cityname);
    prefs.putString("language", cfg->language);
    prefs.putString("weather_key", cfg->weather_key);
    prefs.putString("tianqi_aid", cfg->tianqi_appid);
    prefs.putString("tianqi_as", cfg->tianqi_appsecret);
    prefs.putUChar("backLight", cfg->backLight);
    prefs.putUChar("rotation", cfg->rotation);
    prefs.putUChar("auto_mpu", cfg->auto_calibration_mpu);
    prefs.end(); // 关闭当前命名空间

    
    // config_read("/wifi.txt", &g_cfg);
    // // 立即更改屏幕方向
    // screen.setBackLight(g_cfg.backLight / 100.0);
    // tft->setRotation(g_cfg.rotation);
    
}