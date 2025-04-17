#include <iostream>
using namespace std;

struct Point {			// 화면상의 점을 표현하는 클래스
	int  x, y;		// 점의 x와 y 좌표 값
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { }
	void print() { cout << "\t(" << x << "," << y << ")\n"; }
};

class Line {			// 화면상의 선분을 표현하는 클래스
	Point	p1, p2;		// 선분의 양 끝점
public:
	Line(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {}
	void print() {
		cout << "Line:\n";
		p1.print();
		p2.print();
	}
};

void main()
{
	Point p(1, 2);
	Line l(3, 4, 5, 6);
	p.print();
	l.print();
}