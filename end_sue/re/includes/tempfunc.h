#ifndef _TEMPFUNC_H_
#define _TEMPFUNC_H_

#include "header.h"

using namespace std;

enum TEMP_TYPE
{
    TEMP_TYPE_0 = 0,
    TEMP_TYPE_1
};

class temperature
{
    public:

    temperature(){};
    ifstream in[3];

    int z, counter, end;
    float value = value / 1000;
    
    void sigint_handler(int signo);
    void templocation();
    void Temp_Out();
    void Temp_Zone0(TEMP_TYPE type);
    void Temp_Zone1(TEMP_TYPE type);
};

#endif
