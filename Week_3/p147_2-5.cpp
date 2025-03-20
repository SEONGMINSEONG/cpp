#include <iostream>
#include "p147_2-5.h" 


int reverse(int n) {
    int reversed = 0;
    
    
    while (n != 0) {
        reversed = reversed * 10 + (n % 10);  
        n /= 10;  
    }
    
    return reversed;
}

int main() {
    int number;
    
    std::cout << "정수를 입력하세요: ";
    std::cin >> number;
    
    std::cout << "역순: " << reverse(number) << std::endl;
    
    return 0;
}
