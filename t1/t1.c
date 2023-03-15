#include <stdio.h>
#include <time.h>

#define MAX 1000000

int main(){

    //MK: 시작/끝 시간을 측정하기 위해서 추가함 (time.h 필요)
    struct timespec  begin, end;
    double tmpValue = 0.0;

    //MK: 연산 시작과 함께 시간을 측정함
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for(int i = 0; i < MAX; i++){
        tmpValue += i;
    }

    //MK: 연산이 끝나면 시간을 측정함
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Value: %lf\n", tmpValue);

    //MK: 측정한 시간을 Nano, Micro, Milli, Second 단위로 출력함
    long time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
    printf("Time (Nano): %ld\n", time);
    printf("Time (Micro): %lf\n", (double)time/1000);
    printf("Time (Milli): %lf\n", (double)time/1000000);
    printf("Time (Second): %lf\n", (double)time/1000000000);

    return 0;
    
}