#include <iostream>
using namespace std;

struct Point {
	int  x, y;
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { }
};

Point readPoint() {
	Point p;
	cout << "좌표를 입력해주세요(x,y): ";
	cin >> p.x >> p.y;
	return p;
}
void printPoint(Point p, char* str = "Point") {
	cout << str << "= (" << p.x << "," << p.y << ")\n";
}
void main()
{
	Point a;
	a = readPoint();
	printPoint(a, "입력 좌표");
}