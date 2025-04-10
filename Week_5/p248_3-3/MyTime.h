#ifndef MYTIME_H
#define MYTIME_H

// MyTime 구조체 선언
struct MyTime {
    int hours;    // 시
    int minutes;  // 분
    int seconds;  // 초
    int millis;   // 밀리초
    
};

// 함수 선언 (포인터 방식)
void addTime(MyTime t1, MyTime t2, MyTime* pt);

#endif