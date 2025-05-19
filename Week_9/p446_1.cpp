#include <iostream>

class Point {
protected:
    int x, y;
public:
    Point(int xx, int yy) : x(xx), y(yy) {}
    virtual void draw() { // virtual 키워드 추가 (다형성 지원을 위해) 가상 함수
        std::cout << "(" << x << "," << y << ")에 점을 그려라.\n";
    }
};

class Rectangle : public Point {
protected:
    int width;
    int height;
public:
    Rectangle(int xx, int yy, int w, int h) : Point(xx, yy), width(w), height(h) {}
    void draw() override { // override 키워드 추가 (명시적인 오버라이딩)
        std::cout << "(" << x << "," << y << ")에 가로 " << width << ", 세로 " << height << "인 사각형을 그려라.\n";
    }
};

int main() {
    Point pt(1, 1);
    pt.draw(); // 출력: (1,1)에 점을 그려라.

    Rectangle rect(2, 3, 100, 200);
    rect.draw(); // 출력: (2,3)에 가로 100, 세로 200인 사각형을 그려라.

    return 0;
}


// 4번: 파생 클래스 (Rectangle)에서의 접근 불가: private 접근 지정자는 해당 클래스 내부에서만 멤버에 접근할 수 있도록 제한합니다. 
// 따라서 Point 클래스의 멤버 변수인 x와 y는 이제 Point 클래스 자신의 멤버 함수(예: 생성자, draw())를 통해서만 접근할 수 있게 됩니다. 
// Rectangle 클래스는 더 이상 직접 x와 y에 접근할 수 없습니다.