#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <TFT_eSPI.h>
#include <SPI.h>
#include <iostream>
#include <string>
#include "driver/display.h"
// #include <examples/Generic/drawXBitmap/xbm.h>
// #include <examples/Generic/Animated_Eyes_1/data/logo.h>
#include <../data/logo_3.h>


TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);


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
    tft.setTextColor(TFT_BROWN, TFT_BLACK);

    tft.drawNumber(counter, 110, 100, 2);
}

void show_String(int counter)
{

    // 设置背景色可以防止数字重叠
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);

    char intStr[12];
    sprintf(intStr, "str: %d", counter);
    tft.drawCentreString(intStr, 120, 140, 2);
}

void show_xbm()
{
   
    // Example 1
    int x = (tft.width() - logoWidth) / 2;
    int y = (tft.height() - logoHeight) / 2;

    tft.drawXBitmap(x, y, logo, logoWidth, logoHeight, TFT_WHITE);

    // delay(1000);
 
    // tft.drawXBitmap(x, y, logo, logoWidth, logoHeight, TFT_BLACK);
}

#endif