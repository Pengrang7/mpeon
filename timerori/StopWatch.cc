#include "Utility.h"
// 구조 - 스톱워치 부분
void StopWatch() {
	printf("===== 스톱워치 =====\n");
	printf("아무키나 누르면 시작 합니다.");
	getchar();

	Time_format data;
	clock_t start_time = clock();
	while (1) {
		// 시간 계산 및 시간 포맷 만들기 
		clock_t curr_time = clock() - start_time;
		data = GetTime(curr_time);
		//시간 포맷으로 출력
		printf("\n\n\t%d:%d:%d.%d\n\n", data.hour, data.min, data.sec, data.undersec);

		// //키 입력을 받았을때 멈추기(일시정지)
		//if (_kbhit()) {
		if (1) {

			//일시정지 후 질의 선택
			printf("1.재시작\t2.초기화\t3.종료\n");
			printf("원하는 기능을 선택 하세요 : ");
			int input = Intinput(1, 3);

			//1. 재시작 선택시 스톱워치가 이어서 진행
			if (input == 1) {
				start_time = clock() - curr_time;
				continue;
			}
			//2. 초기화 선택시 스톱워치가 초기화 후 진행
			if (input == 2) {
				start_time = clock();
				continue;
			}
			else {
				break;
			}

		}
		system("clear");
	}
	getchar();
}