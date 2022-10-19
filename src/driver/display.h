#ifndef DISPLAY_H
#define DISPLAY_H

#define LCD_BL_PIN 5
#define LCD_BL_PWM_CHANNEL 0


class Display
{
public:
    void init();
    void routine();
    void setBackLight(float);
};

#endif