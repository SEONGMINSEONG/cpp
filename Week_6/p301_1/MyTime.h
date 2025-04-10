#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <iomanip>

class MyTime {
private:
    int hours;    // 시 (private)
    int minutes;  // 분 (private)
    int seconds;  // 초 (private)
    int millis;   // 밀리초 (private)

public:
    // 생성자
    MyTime();

    // 멤버 함수 선언
    void read();                  // 요구사항 2
    void convert(double duration); // 요구사항 4
    void print();                 // 요구사항 3 & 4
    MyTime add(MyTime t);         // 요구사항 4
    void reset();                 // 요구사항 4

    // addTime을 friend로 선언하여 private 멤버 접근 허용
    friend MyTime addTime(MyTime t1, MyTime t2);
};

// 외부 함수 선언
MyTime addTime(MyTime t1, MyTime t2);

#endif