#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <TFT_eSPI.h>
#include <SPI.h>
#include <iostream>
#include <string>
#include "driver/display.h"

using namespace std;

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

void test_TFT_ESPI()
{
    // draw text
    tft.setCursor(10, 10);
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(2);
    tft.print("stone gread job!");

    tft.setTextColor(TFT_ORANGE);

    tft.drawCentreString("HELLO", 120, 30, 2);
    tft.drawCentreString("WORLD", 120, 60, 2);
}

void show_Number(int counter)
{

    // 设置背景色可以防止数字重叠
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);

    char intStr[6];
    sprintf(intStr, "%d", counter);
    tft.drawCentreString(intStr, 120, 100, 2);
}

void test_init()
{
    // must add 2 line code
    ledcSetup(LCD_BL_PWM_CHANNEL, 5000, 10);
    ledcAttachPin(LCD_BL_PIN, LCD_BL_PWM_CHANNEL);
    ledcWrite(LCD_BL_PWM_CHANNEL, 600);
    // tft init
    tft.init();
    tft.setRotation(4);
    tft.fillScreen(TFT_BLACK);
}

#endif