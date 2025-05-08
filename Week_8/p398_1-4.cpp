#include <iostream>
#include <cstring>

class Sample {
private:
    char *name;
public:
    static int count;
    Sample() {
        count++;
        name = nullptr;
    }
    Sample(const char *name) {
        count++;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Sample(const Sample& other) {
        count++;
        this->name = other.name; // 얕은 복사
    }
    ~Sample() {
        delete[] name;
        count--;
    }
    static void printCount() {
        std::cout << "Sample 객체의 현재 개수: " << count << std::endl;
    }

    const char* getName() const {
        return name;
    }

    // name 멤버 변수의 값을 변경하는 public 함수
    void setName(const char* newName) {
        delete[] name; // 기존 메모리 해제
        if (newName != nullptr) {
            name = new char[strlen(newName) + 1];
            strcpy(name, newName);
        } else {
            name = nullptr;
        }
    }
};

int Sample::count = 0;

int main() {
    Sample::printCount();

    Sample a("Shallow");
    Sample::printCount();
    std::cout << "a의 name: " << a.getName() << std::endl;

    Sample b(a); // 얕은 복사 생성자 호출
    Sample::printCount();
    std::cout << "b의 name: " << b.getName() << std::endl;

    // a의 name 변경 (b도 영향을 받음)
    char newName[] = "Changed";
    a.setName(newName); // setName() 함수를 통해 name 변경
    std::cout << "a의 name 변경 후: " << a.getName() << std::endl;
    std::cout << "b의 name (영향 받음): " << b.getName() << std::endl;

    return 0;
}