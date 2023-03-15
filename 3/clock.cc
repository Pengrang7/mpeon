#define _CRT_SECURE_NO_WARNINGS // 혹은 localtime_s를 사용
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS // 혹은 localtime_s를 사용
#include <time.h>
#include "stdio.h"

using namespace std;


int main() {

    char buf[1024];

    memset(buf, 0x00, 1024);


    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

     buf [0]=0x01;
     buf [1]=0x02;
     buf [2]=0x03;
     buf [3]=0x04;
     buf [4]=0x05;
     buf [5]=0x06;
     buf [6]=0x07; //정수 16진수 비트 연산
     buf [7]=0x08;
    
    printf("유닉스 타임 (Unix Time): %lx 초\n\n", timer); 
    
    buf[4]=timer>>24;
    buf[5]=timer>>16;
    buf[6]=timer>>8;
    buf[7]=timer;

    printf("buf [4]: %x 초\n", buf [4]);
    printf("buf [5]: %x 초\n", buf [5]); 
    printf("buf [6]: %x 초\n", buf [6]); 
    printf("buf [6]: %x 초\n\n", buf [7]); 

    int t1;

    t1 = buf[4]<<24;
    t1 += buf[5]<<16;
    t1 += buf[6]<<8;
    t1 += buf[7];

    printf("buf[4] =  %x \n", buf[4]);
    printf("buf[5] =  %x \n", buf[5]);
    printf("buf[6] =  %x \n", buf[6]);
    printf("buf[7] =  %x \n\n", buf[7]);

    printf("%x %x %x %x \n\n",  buf[4], buf[5], buf[6], buf[7]);

    printf("t1 = %x \n", t1);
    // printf("t2 = %x \n", t2);

    printf("finish \n");



    return 0;
}