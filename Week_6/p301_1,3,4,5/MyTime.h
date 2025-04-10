#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <iomanip>

// MyTime 클래스: 시간 데이터를 관리하는 클래스
class MyTime {
private:
    int hours;    // 시 (private로 외부 접근 차단)
    int minutes;  // 분 (private로 외부 접근 차단)
    int seconds;  // 초 (private로 외부 접근 차단)
    int millis;   // 밀리초 (private로 외부 접근 차단)

public:
    MyTime();     // 기본 생성자: 모든 값을 0으로 초기화
    void read();  // 사용자 입력을 받아 시간 데이터 설정
    void convert(double duration); // 초 단위 시간을 시/분/초/밀리초로 변환
    void print(); // 시간 데이터를 형식화된 문자열로 출력 (01:02:34:567)
    MyTime add(MyTime t); // 두 시간을 더한 결과를 반환
    void reset(); // 모든 시간 데이터를 0으로 초기화
};

#endif