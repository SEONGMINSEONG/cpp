#include <iostream>
#include "MyTime.h"

int main() {
    MyTime time1, time2;

    // 첫 번째 시간 입력
    std::cout << "첫 번째 시간을 입력하세요:\n";
    time1.read();

    // 두 번째 시간 입력
    std::cout << "\n두 번째 시간을 입력하세요:\n";
    time2.read();

    // 두 시간 더하기 (addTime 사용)
    MyTime sum = addTime(time1, time2);

    // 결과 출력
    std::cout << "\n합계: ";
    sum.print();
    std::cout << std::endl;

    return 0;
}