#include "Utility.h"


// 구조 - 타이머 부분
void Timer() {

	Time_format data;
	//타이머 설정 입력 
	int input;
	while (1) {

		data = SetTime();

		//시간 설정 확인
		printf("설정 시간 %d:%d:%d\n", data.hour, data.min, data.sec);
		printf("1. 시작\t2. 재설정\n");
		printf("설정 시간을 확인 해 주세요. : ");
		input = Intinput(1, 2);
		if (input == 1) {
			printf("아무키나 누르면 타이머가 실행됩니다.\n");
			getchar();

			break;
		}
		else {
			printf("아무키나 누르면 타이머가 초기설정화면으로 돌아갑니다.\n");
			getchar();
		}
	}
	// 시간 카운팅 시작 값
	clock_t start_time = clock();
	while (1) {
		system("clear");
		// 0초로 맞춤과 설정 시간 - 소모시간 출력
		clock_t curr_time = clock() - start_time;
		double time_double = (double)curr_time / 1000;
		int curr_sec = (int)time_double;
		int target = data.total - curr_sec;
		printf("\n\n\t%d:%d:%d\n\n", target / 60 / 60, target / 60 % 60, target % 60);

		//키입력시 일시정지
		if (getchar()) {
			getchar();
			printf("1. 이어하기\t2. 재설정\t 3. 종료\n");
			printf("설정 시간을 확인 해 주세요. : ");
			input = Intinput(1, 3);

			//이어하기시
			if (input == 1) {
				printf("아무키나 누르면 타이머가 실행됩니다.\n");
				getchar();
				clock_t stop_time = clock() - (curr_time + start_time);
				start_time += stop_time;
			}

			//다시 설정시
			else if (input == 2) {
				while (1) {
					data = SetTime();
					//시간 설정 확인
					printf("설정 시간 %d:%d:%d\n", data.hour, data.min, data.sec);
					printf("1. 시작\t2. 재설정\n");
					printf("설정 시간을 확인 해 주세요. : ");
					scanf("%d", &input);
					if (input == 1) {
						printf("아무키나 누르면 타이머가 실행됩니다.\n");
						getchar();
						start_time = clock();
						break;
					}
					else {
						printf("아무키나 누르면 타이머가 초기설정화면으로 돌아갑니다.\n");
						getchar();
					}
				}
			}
			else {
				break;
			}

		}

		//시간 소모시 탈출
		if (target == 0) {
			printf("설정하신 시간이 모두 소모되었습니다.\n");
			getchar();
			break;

		}
	}
}