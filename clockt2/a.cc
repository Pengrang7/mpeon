/*

10 초를 카운트 다운 한다.

이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/clock/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

void wait(int seconds) {
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait) {
  }
}

int main() {
  int n;
  printf("Starting countdown...\n");
  for (n = 10; n > 0; n--) {
    printf("%d\n", n);
    wait(1);
  }
  printf("FIRE!!!\n");
  return 0;
}