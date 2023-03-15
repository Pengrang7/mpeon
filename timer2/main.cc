#include <iostream>

using namespace std;

//입력한 초가 지나면 글자가 출력되면서 강제 종료되는 코드
//시간이 안 맞음

int main()
{
    int second = 0;
    cout<<"초를 입력해 주세요: ";
    cin>>second;
    
    clock_t start = clock();
    
    clock_t end = clock();
    
    while (true) {
        end = clock();
        
        if (double(end - start) / CLOCKS_PER_SEC == second) {
            break;
        }
    }
    
    cout<<"끄읕! \n";
}