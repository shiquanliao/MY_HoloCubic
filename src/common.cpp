#include "common.h"

Preferences prefs; // 声明Preferences对象
Config g_cfg;      // 全局配置文件 
Display screen;    // 屏幕对象

TFT_eSPI* tft = new TFT_eSPI();
TFT_eSprite* img = new TFT_eSprite(tft);