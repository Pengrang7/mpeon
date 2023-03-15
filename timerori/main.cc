#include "Utility.h"

// 타이머는 멀쩡한데 스톱워치가 안 됨.

int main() {

	//프로그램 시작
	while (1) {
		//메인 화면 부분
		system("cls");
		printf("\t=== Test Program ==\n\n");
		int input;
		printf("1.스톱워치\t2.타이머\t3.종료\n\n");
		printf("원하는 메뉴를 입력 하세요 : ");
		input = Intinput(1, 3);
		//메뉴 입력 후 동작하기
		//정상적인 입력이면
		if (input > 0 && input < 4) {
			//종료 입력시
			if (input == 3) {
				printf("프로그램을 종료 합니다.");
				break;
			}
			//스톱워치 또는 타이머 부분
			switch (input)
			{
			//스톱워치
			case 1:
				StopWatch();
				break;
			//타이머
			case 2:
				Timer();
				break;
			}
		}
		//예외 발생 시 
		else {
			while (getchar() != '\n') {}
			printf("잘못된 입력입니다.");
			getchar();
		}
	}
	return 0;
}