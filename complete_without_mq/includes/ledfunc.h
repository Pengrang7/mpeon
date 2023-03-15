#ifndef _LEDFUNC_H_
#define _LEDFUNC_H_

#include <iostream>
#include <fstream>

using namespace std;

// extern int gpio_num,led_num;

enum LED_TYPE
{
    LED_TYPE_GNSS = 0,
    LED_TYPE_WAVE,
    LED_TYPE_C_V2X,
    LED_TYPE_5G,
    LED_TYPE_RUN
};

class led
{
public:

int gpio_num, led_num;

led();

ofstream ledout[5];

void On(LED_TYPE type);
void Off(LED_TYPE type);
void Out();
// int led_init();

};

#endif