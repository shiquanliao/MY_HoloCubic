#include "common.h"

Preferences prefs; // 声明Preferences对象
Config g_cfg;      // 全局配置文件 
Display screen;    // 屏幕对象

TFT_eSPI* tft = new TFT_eSPI();
TFT_eSprite* img = new TFT_eSprite(tft);

boolean doDelayMillisTime(unsigned long interval, unsigned long *previousMillis, boolean state)
{
    unsigned long currentMillis = millis();
    if (currentMillis - *previousMillis >= 20)
    {
        Serial.printf("init cost: %d", currentMillis - *previousMillis);
    }
    if (currentMillis - *previousMillis >= interval)
    {
        *previousMillis = currentMillis;
        state = !state;
    }
    return state;
}