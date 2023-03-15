#include "Utility.h"

// 기능 - 예외처리 메뉴 입력
int Intinput(int min, int max) {
	int input;
	while (1) {
		scanf("%d", &input);
		if (input >= min && input <= max) {
			return input;
		}
		else {
			while (getchar() != '\n') {}
			printf("잘못된 입력입니다. 다시 입력해주세요. : ");
		}
	}
}
// 기능 - 시간 처리
Time_format GetTime(clock_t time) {
	Time_format data;
	double tempd = (double)time / 1000;
	int tempi = (int)tempd;
	data.hour = tempi / 60 / 60;
	data.min = tempi / 60 % 60;
	data.sec = tempi % 60;
	data.undersec = time % 1000;
	return data;
}
Time_format SetTime() {
	Time_format data;
	int set_total = 0;
	system("clear");
	set_total = 0;
	printf("시간을 입력해 주세요 : ");
	set_total = Intinput(0, INT_MAX) * 60 * 60;
	system("clear");
	printf("분을 입력해 주세요 : ");
	set_total += Intinput(0, INT_MAX) * 60;
	system("clear");
	printf("초를 입력해 주세요 : ");
	set_total += Intinput(0, INT_MAX);
	system("clear");
	data = GetTime((clock_t)(set_total * 1000));
	data.total = set_total;
	return data;
}