#include <stdio.h>
#include "calc_data.h" //값 받아오는 헤더
#include "Minus.h"     //빼기용 헤더

//빼기 계산 -> main.c 로 리턴
int Minus(CALC_DATA a_data)
{
    return a_data.a-a_data.b;
}
