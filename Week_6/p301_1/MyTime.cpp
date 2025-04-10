#include "MyTime.h"

// 생성자 구현
MyTime::MyTime() : hours(0), minutes(0), seconds(0), millis(0) {}

// 사용자 입력을 받는 함수 (요구사항 2)
void MyTime::read() {
    std::cout << "시간을 입력하세요:\n";
    std::cout << "시: ";
    std::cin >> hours;
    std::cout << "분: ";
    std::cin >> minutes;
    std::cout << "초: ";
    std::cin >> seconds;
    std::cout << "밀리초: ";
    std::cin >> millis;
}

// 초 단위의 시간을 변환 (요구사항 4)
void MyTime::convert(double duration) {
    millis = static_cast<int>(duration * 1000) % 1000;
    seconds = static_cast<int>(duration) % 60;
    minutes = static_cast<int>(duration / 60) % 60;
    hours = static_cast<int>(duration / 3600);
}

// 시간 출력 함수 (요구사항 3 & 4)
void MyTime::print() {
    std::cout << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setfill('0') << std::setw(2) << minutes << ":"
              << std::setfill('0') << std::setw(2) << seconds << ":"
              << std::setfill('0') << std::setw(3) << millis;
}

// 두 시간을 더하는 멤버 함수 (요구사항 4)
MyTime MyTime::add(MyTime t) {
    MyTime result;
    result.millis = (millis + t.millis) % 1000;
    int carrySeconds = (millis + t.millis) / 1000;
    result.seconds = (seconds + t.seconds + carrySeconds) % 60;
    int carryMinutes = (seconds + t.seconds + carrySeconds) / 60;
    result.minutes = (minutes + t.minutes + carryMinutes) % 60;
    int carryHours = (minutes + t.minutes + carryMinutes) / 60;
    result.hours = hours + t.hours + carryHours;
    return result;
}

// 모든 값을 0으로 초기화 (요구사항 4)
void MyTime::reset() {
    hours = 0;
    minutes = 0;
    seconds = 0;
    millis = 0;
}

// 외부 함수 구현 (friend로 private 멤버 접근 가능)
MyTime addTime(MyTime t1, MyTime t2) {
    MyTime result;
    result.millis = (t1.millis + t2.millis) % 1000;
    int carrySeconds = (t1.millis + t2.millis) / 1000;
    result.seconds = (t1.seconds + t2.seconds + carrySeconds) % 60;
    int carryMinutes = (t1.seconds + t2.seconds + carrySeconds) / 60;
    result.minutes = (t1.minutes + t2.minutes + carryMinutes) % 60;
    int carryHours = (t1.minutes + t2.minutes + carryMinutes) / 60;
    result.hours = t1.hours + t2.hours + carryHours;
    return result;
}