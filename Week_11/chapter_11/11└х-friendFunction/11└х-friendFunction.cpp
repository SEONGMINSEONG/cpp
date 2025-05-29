#pragma once
#include <cstdio>

class Point {
	int x, y;		// private 멤버
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { }
	void print(char *s = "점") { printf("%s(%d,%d)", s, x, y); }

	friend double avgPointX(Point* list, int n);	// 평균 x값 계산하는 일반 함수
	friend Point addPoint(Point& p, Point& q) {	// 두 Point를 더하는 일반 함수
		Point	r;
		r.x = p.x + q.x;
		r.y = p.y + q.y;
		return r;
	}
	friend Point subPoint(Point& p, Point& q) {	// 두 Point를 빼는 일반 함수
		return Point(p.x - q.x, p.y - q.y);
	}
};
// double Point::avgPointX(...)가 아님
double avgPointX(Point* list, int n) {	// friend 함수는 일반함수임
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += list[i].x;
	return sum / n;
}

void main()
{
	Point arr[5] = { Point(0, 1), Point(2, 3), Point(4, 5) };
	arr[3] = addPoint(arr[0], arr[1]);
	arr[4] = subPoint(arr[2], arr[1]);
	for (int i = 0; i < 5; i++)
		arr[i].print();
	printf("\nAverage X = %lf\n", avgPointX(arr, 5));
}