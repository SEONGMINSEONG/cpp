#include <iostream>
#include "MyTime.h"

// 두 시간을 더하는 함수 구현 (참조 방식)
void addTime(MyTime t1, MyTime t2, MyTime& t3) {
    // 밀리초 계산
    t3.millis = (t1.millis + t2.millis) % 1000;
    int carrySeconds = (t1.millis + t2.millis) / 1000;
    
    // 초 계산
    t3.seconds = (t1.seconds + t2.seconds + carrySeconds) % 60;
    int carryMinutes = (t1.seconds + t2.seconds + carrySeconds) / 60;
    
    // 분 계산
    t3.minutes = (t1.minutes + t2.minutes + carryMinutes) % 60;
    int carryHours = (t1.minutes + t2.minutes + carryMinutes) / 60;
    
    // 시 계산
    t3.hours = t1.hours + t2.hours + carryHours;
}

// 메인 함수
int main() {
    MyTime time1, time2, result;

    // 첫 번째 시간 입력
    std::cout << "첫 번째 시간을 입력하세요:\n";
    std::cout << "시: ";
    std::cin >> time1.hours;
    std::cout << "분: ";
    std::cin >> time1.minutes;
    std::cout << "초: ";
    std::cin >> time1.seconds;
    std::cout << "밀리초: ";
    std::cin >> time1.millis;

    // 두 번째 시간 입력
    std::cout << "\n두 번째 시간을 입력하세요:\n";
    std::cout << "시: ";
    std::cin >> time2.hours;
    std::cout << "분: ";
    std::cin >> time2.minutes;
    std::cout << "초: ";
    std::cin >> time2.seconds;
    std::cout << "밀리초: ";
    std::cin >> time2.millis;

    // 두 시간 더하기 (result에 결과 저장)
    addTime(time1, time2, result);

    // 결과 출력
    std::cout << "\n합계: " 
              << result.hours << "시간 " 
              << result.minutes << "분 " 
              << result.seconds << "초 " 
              << result.millis << "밀리초" << std::endl;

    return 0;
}