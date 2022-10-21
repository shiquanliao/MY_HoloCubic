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

void mpu_config_read(const char *file_path, Config *cfg)
{

    prefs.begin("MPU_Config"); // 打开命名空间mynamespace
    cfg->mpu_config.x_gyro_offset = prefs.getInt("x_gyro_offset", 0);
    cfg->mpu_config.y_gyro_offset = prefs.getInt("y_gyro_offset", 0);
    cfg->mpu_config.z_gyro_offset = prefs.getInt("z_gyro_offset", 0);
    cfg->mpu_config.x_accel_offset = prefs.getInt("x_accel_offset", 0);
    cfg->mpu_config.y_accel_offset = prefs.getInt("y_accel_offset", 0);
    cfg->mpu_config.z_accel_offset = prefs.getInt("z_accel_offset", 0);
    prefs.end(); // 关闭当前命名空间
}

void mpu_config_save(const char *file_path, Config *cfg)
{
    prefs.begin("MPU_Config"); // 打开命名空间mynamespace
    prefs.putInt("x_gyro_offset", cfg->mpu_config.x_gyro_offset);
    prefs.putInt("y_gyro_offset", cfg->mpu_config.y_gyro_offset);
    prefs.putInt("z_gyro_offset", cfg->mpu_config.z_gyro_offset);
    prefs.putInt("x_accel_offset", cfg->mpu_config.x_accel_offset);
    prefs.putInt("y_accel_offset", cfg->mpu_config.y_accel_offset);
    prefs.putInt("z_accel_offset", cfg->mpu_config.z_accel_offset);

    prefs.end(); // 关闭当前命名空间
}