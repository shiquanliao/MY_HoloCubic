#ifndef COMMON_H
#define COMMON_H

#define AIO_VERSION "1.0.0"

#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI* tft =new TFT_eSPI();
TFT_eSprite img = TFT_eSprite(tft);


#endif