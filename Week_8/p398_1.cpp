#include <iostream>
#include <cstring>

class Sample {
private:
    char *name;         // name은 동적 할당된 문자열을 가리키는 포인터
public:
    static int count;   // Sample 클래스의 전체 객체 수를 추적 (정적 변수)

    // 기본 생성자 (name을 초기화하고 count 증가)
    Sample() 
    {
        count++;
        name = nullptr; 
    }

    // 문자열을 받아서 객체 생성 (name 메모리 동적 할당)
    Sample(const char *name) 
    {
        count++;
        this->name = new char[strlen(name) + 1];   // 문자열 크기만큼 메모리 확보
        strcpy(this->name, name);                   // 문자열 복사
    }

    // 복사 생성자 (깊은 복사 수행)
    Sample(const Sample& other) 
    {
        count++;
        this->name = new char[strlen(other.name) + 1];  // 새 메모리 확보
        strcpy(this->name, other.name);                  // 문자열 내용 복사
    }

    // 소멸자 (동적 메모리 해제 및 count 감소)
    ~Sample() 
    {
        delete[] name;          
        count--;
    }

    // 현재 Sample 객체 개수 출력 (정적 함수)
    static void printCount() 
    {
        std::cout << "Sample 객체의 현재 개수: " << count << std::endl;
    }

    // name 값 출력 (객체 상태 확인용)
    void printName() const 
    {
        if (name != nullptr)
            std::cout << "name: " << name << std::endl;
        else
            std::cout << "name: (null)" << std::endl;
    }
};

// 정적 변수 count 초기화 (프로그램 시작 시 0으로)
int Sample::count = 0;

int main() {
    Sample::printCount();   // 객체 생성 전 개수 출력 (0)

    char inputName[100];   
    std::cout << "첫 번째 객체의 name을 입력하세요: ";
    std::cin.getline(inputName, 100);   // 사용자로부터 문자열 입력

    Sample a(inputName);    // 입력받은 name으로 a 객체 생성
    a.printName();          // a 객체의 name 출력
    Sample::printCount();   // 객체 개수 출력 (1)

    std::cout << "a 객체를 복사해서 b 객체를 만듭니다.\n";
    Sample b(a);            // a 객체를 복사해서 b 객체 생성 (깊은 복사)
    b.printName();          // b 객체의 name 출력
    Sample::printCount();   // 객체 개수 출력 (2)

    return 0;
    // main 끝날 때 a, b 소멸자 호출 → 동적 메모리 해제, count 감소
}
