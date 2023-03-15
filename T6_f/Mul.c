#include <stdio.h>
#include "calc_data.h"
#include "Mul.h"

//곱하기 계산 -> main.c 로 리턴
int Mul(CALC_DATA a_data)
{
    return a_data.a*a_data.b;
}
