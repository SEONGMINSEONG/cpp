#include <iostream>            // 방법 2 선언 이후 같은 파일에 정의와 main함수 작성
using namespace std;           //헤더 파일 포함

int reverse(int n);            // 선언

int main() {                   // 프로그램의 시작점
    int num;                   // 사용자 입력 값을 저장할 변수
    cout << "Enter a number: ";                    // 입력
    cin >> num;                                    // 사용자가 입력한 값을 num에 저장
    cout << "Reversed: " << reverse(num) << endl;  // 출력
    return 0;                  // reverse 함수 호출
}

int reverse(int n) {           //reverse 함수는 숫자의 자릿수를 뒤집는 역할(정의)
    int rev = 0;               // 1. rev를 0으로 초기화
    while (n != 0) {           // n이 0이 될 때까지 계속 반복한다는 의미
        rev = rev * 10 + n % 10;     // 2. 마지막 자릿수(n % 10)를 rev에 더함
        n /= 10;               // 마지막 자릿수를 제거
    }
    return rev;                // rev에는 뒤집힌 숫자가 저장되어 있음
}
