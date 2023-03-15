#ifndef _UI_MAIN_H_
#define _UI_MAIN_H_

#include <thread>

#include "tempfunc.h"
#include "ledfunc.h"

enum UI_INSERT
{
    UI_LED = 0,
    UI_TEMP,
    UI_GPS
};


class UI_MAIN
{
    public:

    UI_MAIN(){};
    int insert;
    void main_ui_init(UI_INSERT type);
};

#endif