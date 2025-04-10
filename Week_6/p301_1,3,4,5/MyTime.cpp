#include "MyTime.h"

// 기본 생성자: 객체 생성 시 모든 멤버 변수를 0으로 설정
MyTime::MyTime() : hours(0), minutes(0), seconds(0), millis(0) {}

// read 함수: 사용자로부터 시간 정보를 입력받음
void MyTime::read() {
    std::cout << "시간을 입력하세요:\n"; // 입력 안내 메시지
    std::cout << "시: "; std::cin >> hours;    // 시 입력
    std::cout << "분: "; std::cin >> minutes;  // 분 입력
    std::cout << "초: "; std::cin >> seconds;  // 초 입력
    std::cout << "밀리초: "; std::cin >> millis; // 밀리초 입력
}

// convert 함수: 초 단위의 시간을 시/분/초/밀리초로 변환
void MyTime::convert(double duration) {
    millis = static_cast<int>(duration * 1000) % 1000; // 밀리초 계산
    seconds = static_cast<int>(duration) % 60;         // 초 계산
    minutes = static_cast<int>(duration / 60) % 60;    // 분 계산
    hours = static_cast<int>(duration / 3600);         // 시 계산
}

// print 함수: 시간 데이터를 "01:02:34:567" 형식으로 출력
void MyTime::print() {
    std::cout << std::setfill('0') << std::setw(2) << hours << ":"    // 시 출력 (2자리, 0 채움)
              << std::setfill('0') << std::setw(2) << minutes << ":"  // 분 출력 (2자리, 0 채움)
              << std::setfill('0') << std::setw(2) << seconds << ":"  // 초 출력 (2자리, 0 채움)
              << std::setfill('0') << std::setw(3) << millis;        // 밀리초 출력 (3자리, 0 채움)
}

// add 함수: 현재 객체와 입력 객체의 시간을 더한 결과를 반환
MyTime MyTime::add(MyTime t) {
    MyTime result; // 결과 객체 생성
    result.millis = (millis + t.millis) % 1000; // 밀리초 더하기 (1000 넘으면 초로 올림)
    int carrySeconds = (millis + t.millis) / 1000; // 밀리초에서 초로 올림값
    result.seconds = (seconds + t.seconds + carrySeconds) % 60; // 초 더하기 (60 넘으면 분으로 올림)
    int carryMinutes = (seconds + t.seconds + carrySeconds) / 60; // 초에서 분으로 올림값
    result.minutes = (minutes + t.minutes + carryMinutes) % 60; // 분 더하기 (60 넘으면 시로 올림)
    int carryHours = (minutes + t.minutes + carryMinutes) / 60; // 분에서 시로 올림값
    result.hours = hours + t.hours + carryHours; // 시 더하기
    return result; // 계산된 결과 반환
}

// reset 함수: 모든 시간 데이터를 0으로 초기화
void MyTime::reset() {
    hours = 0;    // 시를 0으로
    minutes = 0;  // 분을 0으로
    seconds = 0;  // 초를 0으로
    millis = 0;   // 밀리초를 0으로
}