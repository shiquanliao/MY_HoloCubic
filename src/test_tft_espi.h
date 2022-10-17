#ifndef TEST_TFT_ESPI_H
#define TEST_TFT_ESPI_H

#include <TFT_eSPI.h>
#include <SPI.h>
#include <iostream>
#include <string>
#include "driver/display.h"
#include <PNGdec.h>
// #include <examples/Generic/drawXBitmap/xbm.h>
// #include <examples/Generic/Animated_Eyes_1/data/logo.h>
#include <examples/PNG Images/Flash_PNG/panda.h>
#include <../data/imgBigSon.h>
#include <../data/logo_3.h>
#include <font_xingkai_gb1803020.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

PNG png; // PNG decoder instance

#define MAX_IMAGE_WDITH 240 // Adjust for your images
#define IMAGE_NAME bigSon
int16_t xpos = 0;
int16_t ypos = 0;


void pngDraw(PNGDRAW *pDraw);

void test_init()
{
    // must add 2 line code
    ledcSetup(LCD_BL_PWM_CHANNEL, 5000, 10);
    ledcAttachPin(LCD_BL_PIN, LCD_BL_PWM_CHANNEL);
    ledcWrite(LCD_BL_PWM_CHANNEL, 50);
    // tft init
    tft.init();
    tft.setRotation(4);
    tft.fillScreen(TFT_BLACK);
}

void test_TFT_ESPI()
{
    tft.loadFont(font_xingkai);
    // draw text
    tft.setCursor(10, 10);
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(1);
    tft.print("stone gread job!");

    tft.setTextColor(TFT_ORANGE);

    tft.drawCentreString("石泉", 120, 60, 1);
    tft.drawCentreString("LOVE", 120, 100, 1);
    tft.drawCentreString("杨柳", 120, 140, 1);

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

void show_img()
{
    tft.fillScreen(TFT_BLACK);
    int16_t rc = png.openFLASH((uint8_t *)IMAGE_NAME, sizeof(IMAGE_NAME), pngDraw);
    if (rc == PNG_SUCCESS)
    {
        Serial.println(F("Successfully png file"));
        Serial.printf("imag specs: (%d x %d), %d bpp, pixel type: %d\n", png.getWidth(), png.getHeight(), png.getBpp(), png.getPixelType());
        tft.startWrite();
        uint32_t dt = millis();
        rc = png.decode(NULL, 0);
        Serial.print(millis() - dt);
        Serial.println(F("ms"));
        tft.endWrite();
    }
    else
    {
        Serial.printf("openFLASH rc: %d", rc);
        Serial.println(" error");
    }
}

void show_chinese()
{

    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.drawCentreString("爱", 120, 30, 2);
}

//=========================================v==========================================
//                                      pngDraw
//====================================================================================
// This next function will be called during decoding of the png file to
// render each image line to the TFT.  If you use a different TFT library
// you will need to adapt this function to suit.
// Callback function to draw pixels to the display
void pngDraw(PNGDRAW *pDraw)
{
    uint16_t lineBuffer[MAX_IMAGE_WDITH];
    png.getLineAsRGB565(pDraw, lineBuffer, PNG_RGB565_BIG_ENDIAN, 0xffffffff);
    tft.pushImage(xpos + (tft.width() - pDraw->iWidth) / 2, ypos + pDraw->y, pDraw->iWidth, 1, lineBuffer);
}

#endif