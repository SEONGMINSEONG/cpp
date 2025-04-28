#include <iostream>
#include "MyTime.h"

// 프로그램 시작점
int main() {
    MyTime t1, t2, t3; // 세 개의 MyTime 객체 생성 (t1, t2: 입력용, t3: 결과용)
    
    std::cout << "첫 번째 시간을 입력하세요:\n"; // 첫 번째 시간 입력 안내
    t1.read(); // t1 객체에 시간 입력
    std::cout << "두 번째 시간을 입력하세요:\n"; // 두 번째 시간 입력 안내
    t2.read(); // t2 객체에 시간 입력
    
    t3 = t1.add(t2); // t1과 t2를 더해 t3에 저장
    std::cout << "결과: "; // 결과 출력 안내
    t3.print(); // t3의 시간 데이터를 출력
    std::cout << std::endl; // 줄바꿈
    
    return 0; // 프로그램 종료
}               //g++ -o mytime main.cpp MyTime.cpp
                //./mytime