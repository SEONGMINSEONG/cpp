#include <iostream>
#include "MyTime.h"

int main() {
    MyTime t1, t2, t3;
    
    std::cout << "첫 번째 시간을 입력하세요:\n";
    t1.read();
    std::cout << "두 번째 시간을 입력하세요:\n";
    t2.read();
    
    t3 = t1.add(t2);
    std::cout << "결과: ";
    t3.print();
    std::cout << std::endl;
    
    return 0;
}     //g++ -o mytime main.cpp MyTime.cpp
      //./mytime