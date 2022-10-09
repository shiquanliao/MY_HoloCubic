#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

void test_TFT_ESPI()
{
    
}

void test_init()
{
    // tft init
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_GREEN);

}

#endif