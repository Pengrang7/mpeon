#include <stdio.h>
#include "calc_data.h"
#include "input.h"


//정수값 2개 입력 받기
void InputValue(CALC_DATA *ap_data)
{
    printf("2number : " );
    scanf("%d %d", &ap_data->a, &ap_data->b);
}

//연산자 입력 받기 -> ShowResult 로 연결
void InputOp(CALC_DATA *ap_data)
{
    printf("(+:1, -:2, *:3, /:4)\n");
    printf("choose(ex, 2): ");
    scanf("%d", &ap_data->op);
}
