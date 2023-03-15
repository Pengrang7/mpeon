#define _CRT_SECURE_NO_WARNINGS // 혹은 localtime_s를 사용
#include <stdio.h>
#include <time.h>

int main() {
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
    
    printf("유닉스 타임 (Unix Time): %lld 초\n\n", timer); 
    printf("현재 년: %d\n", t->tm_year + 1900);
    printf("현재 월: %d\n", t->tm_mon + 1);
    printf("현재 일: %d\n", t->tm_mday);
    printf("현재 시: %d\n", t->tm_hour);
    printf("현재 분: %d\n", t->tm_min);
    printf("현재 초: %d\n", t->tm_sec);
    printf("현재 요일: %d\n", t->tm_wday); // 일=0, 월=1, 화=2, 수=3, 목=4, 금=5, 토=6
    printf("올해 몇 번째 날: %d\n", t->tm_yday); // 1월 1일은 0, 1월 2일은 1
    printf("서머타임 적용 여부: %d\n", t->tm_isdst); // 실시 중이면 양수, 미실시면 0, 실시 정보가 없으면 음수
    
    return 0;
}
