#include "header.h"

void exmaple() // 입력 예시
{
    timer.timer = time(NULL); //타이머
    timer.t = localtime(&timer.timer);

    printf("┌──────────────────────────────────────────────────────┐\n│");
    printf("현재 시간 : %d시 %d분 %d초                             │\n│", timer.t->tm_hour, timer.t->tm_min, timer.t->tm_sec);
    printf("모든 시간은 1초 단위입니다.                           │\n│");
    printf("LED :  1  LedNum  StartTime  EndTime     pattern      │\n│");
    printf("     ( 1   1~5      free      free        1~3       ) │\n│");
    printf("                                                      │\n│");
    printf("TEMP : 2 TEMPNum  StartTime  EndTime    Interval      │\n│");
    printf("     ( 2   1~2      free      free        1~9       ) │\n│");
    printf("                                                      │\n│");
    printf("GPS :  3    ?     StartTime  EndTime    Interval      │\n│");
    printf("     ( 3   1~2      free      free        1~9       ) │\n│");
    printf("                                                      │\n│");
    printf("StartTime : 입력한 만큼 대기 후 동작을 시작합니다.    │\n│");
    printf("EndTime : 입력한 만큼 대기 후 동작을 종료합니다.      │\n│");
    printf("Interval : 입력한 주기로 정보를 받아옵니다.           │\n│");
    printf("띄어쓰기를 구분해서 입력해주세요.                           │\n");
    printf("└──────────────────────────────────────────────────────┘\n");
}

//  https://blog-of-gon.tistory.com/214