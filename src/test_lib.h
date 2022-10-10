#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <TFT_eSPI.h>
#include <SPI.h>
#include "driver/display.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

void test_TFT_ESPI()
{
    
}

void test_init()
{
    // must add 2 line code 
    ledcSetup(LCD_BL_PWM_CHANNEL, 5000, 8);
    ledcAttachPin(LCD_BL_PIN, LCD_BL_PWM_CHANNEL);
    // tft init
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_ORANGE);

}

#endif