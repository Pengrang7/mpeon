#include <stdio.h>
#include "calc_data.h"
#include "calc.h"
#include "Div.h"
#include "Minus.h"
#include "Mul.h"
#include "input.h"

//연산 -> 결과 출력
// InputOp 에서 받은 op 값으로 각 연산 호출
void ShowResult(CALC_DATA a_data)
{
    if(a_data.op>=1 && a_data.op<=4)
    {
        int result;

        if(a_data.op==1) result=Add(a_data);
        else if(a_data.op==2) result=Minus(a_data);
        else if(a_data.op==3) result=Mul(a_data);
        else result=Div(a_data); 

        printf("result: %d \n", result); //결과 출력
    }
    else{printf("no operator \n");} // 값이 1~4 사이가 아니면 나옴
}

int main()
{
    // char select='y';  //계산 반복 대기
    int run=1;
    CALC_DATA data;

    // printf("run more?: \n");
    // rewind(stdin);
    // scanf("%c", &select);    
    while(run==1)
    {        
        InputValue(&data);
        InputOp(&data);
        ShowResult(data);

        printf("run more?(0:stop / 1: run): \n");
        //rewind(stdin);
        scanf("%d", &run);
        if(run==0) break;
    }
    return 0;
}

// //정수값 2개 입력 받기
// void InputValue(CALC_DATA *ap_data)
// {
//     printf("2number : " );
//     scanf("%d %d", &ap_data->a, &ap_data->b);
// }

// //연산자 입력 받기 -> ShowResult 로 연결
// void InputOp(CALC_DATA *ap_data)
// {
//     printf("(+:1, -:2, *:3, /:4)\n");
//     printf("choose(ex, 2): ");
//     scanf("%d", &ap_data->op);
// }
