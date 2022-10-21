#ifndef COMMON_H
#define COMMON_H

#define AIO_VERSION "1.0.0"

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <Preferences.h>
#include "config.h"
#include "driver/display.h"

extern Config g_cfg;      // 全局配置文件
extern Preferences prefs; // 声明Preferences对象
extern Display screen;    // 屏幕对象

extern TFT_eSPI *tft;
extern TFT_eSprite *img;

boolean doDelayMillisTime(unsigned long interval,
                          unsigned long *previousMillis,
                          boolean state);

#endif