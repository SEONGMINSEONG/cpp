#include <iostream>
#include <cstring> 

class Sample {
private:
    char *name;
public:
    static int count;
    Sample() {
        count++;
    }
    Sample(const char * name) {
        count++;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Sample(const Sample& other) {
        count++;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    ~Sample() {
        delete[] name;
        count--;
    }
    static void printCount() {
        std::cout << "Sample 객체의 현재 개수: " << count << std::endl;
    }
};

int Sample::count = 0;

int main() {
    Sample::printCount();

    Sample a("Sample");
    Sample::printCount();

    Sample b(a);
    Sample::printCount();

    return 0;
}