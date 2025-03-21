#include <iostream>
using namespace std;      //헤더 파일 포함

int reverse(int n) {      //reverse 함수는 숫자의 자릿수를 뒤집는 역할
    int rev = 0;          // 1. rev를 0으로 초기화
    while (n != 0) {      // n이 0이 될 때까지 계속 반복한다는 의미
        rev = rev * 10 + n % 10;  // 2. 마지막 자릿수(n % 10)를 rev에 더함
        n /= 10;                  // 마지막 자릿수를 제거
    }
    return rev;           // 최종적으로 뒤집힌 숫자 반환
}

int main() {              // 프로그램의 시작점
    int num;
    cout << "Enter a number: ";   // 
    cin >> num;
    cout << "Reversed: " << reverse(num) << endl;
    return 0;
}