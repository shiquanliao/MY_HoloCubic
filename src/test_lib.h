#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <TFT_eSPI.h>
#include <SPI.h>
#include "driver/display.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

void test_TFT_ESPI()
{
    // draw text
    tft.setCursor(10, 10);
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(2);
    tft.print("stone gread job!");
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