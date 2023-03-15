#include "header.h"

void input()
{
    printf(" input : "); // op코드, led 번호, 시작 시간, 끝나는 시간, 패턴(또는 인터벌) 순서로 받음
    scanf("%1d %1d %d %d %1d", &data.opcode, &data.LedNum, &timer.StartTime, &timer.EndTime, &data.patter);

    printf(" wait %d \n", timer.StartTime*1); // 대기(시작) 시간

    sleep(timer.StartTime*1); // 시작 시간만큼 대기
}

