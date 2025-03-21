#include <iostream>          // 방법 3 함수 선언 in 헤더 파일 함수 정의, 호출 in 소스 파일
#include "p147_2-5.h"        //선언


int reverse(int n) {         //reverse 함수는 숫자의 자릿수를 뒤집는 역할(정의)
    int reversed = 0;        // 1. rev를 0으로 초기화
    
    
    while (n != 0) {         // n이 0이 될 때까지 계속 반복한다는 의미
        reversed = reversed * 10 + (n % 10);    // 2. 마지막 자릿수(n % 10)를 rev에 더함
        n /= 10;             // 마지막 자릿수를 제거
    }
    
    return reversed;         // rev에는 뒤집힌 숫자가 저장되어 있음
}

int main() {                 // 프로그램의 시작점
    int number;              // 입력
    
    std::cout << "정수를 입력하세요: ";      // 입력
    std::cin >> number;      // 사용자가 입력한 값을 num에 저장
    
    std::cout << "역순: " << reverse(number) << std::endl;  // 출력
                            // reverse 함수 호출 
    return 0;               // 정상 종료
}
