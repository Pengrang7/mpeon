#include <stdio.h>
#include "calc_data.h"
#include "Div.h"

//나누기 계산 -> main.c 로 리턴
int Div(CALC_DATA a_data)
{
    return a_data.a/a_data.b;
}
