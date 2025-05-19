#pragma once
#include "Canvas.h"

class Point {
public:
	int x, y;	// 점의 좌표
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	void move(int dx, int dy) { x += dx; y += dy; }
};
class Shape {
protected:
	Point p;		// 형태의 위치
public:
	Shape(int x = 0, int y = 0) : p(x, y) {}
	void draw(Canvas& canvas, string color = "★") {
		canvas.draw(p.x, p.y, color);
	}
	void move(int dx, int dy) { p.move(dx, dy); }
};

// 선분과 관련된 클래스들 --------------------------------------------------------
inline int Abs(int x) { return x > 0 ? x : -x; }
inline int Max(int x, int y) { return x > y ? x : y; }
inline int Round(double x) { return (int)(x + 0.5); }
class Line : public Shape {
	Point q;		//  선분의 다른 쪽 끝점 (한쪽 끝점은 p임)
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
		: Shape(x1, y1), q(x2, y2) { }
	void draw(Canvas& canvas, string color = "선") {
		int len = Max(Abs(q.x - p.x), Abs(q.y - p.y));
		double x = p.x, y = p.y;
		double dx = (q.x - p.x) / (double)len, dy = (q.y - p.y) / (double)len;
		for (int i = 0; i <= len; i++) {
			canvas.draw(Round(x), Round(y), color);
			x += dx;
			y += dy;
		}
	}
	void move(int dx, int dy) { p.move(dx, dy); q.move(dx, dy); }
};

class HLine : public Line {
public:
	HLine(int x = 0, int y = 0, int len = 0) : Line(x, y, x + len, y) { }
};
class VLine : public Line {
public:
	VLine(int x = 0, int y = 0, int len = 0) : Line(x, y, x, y + len) { }
};

// 사각형과 관련된 클래스들 --------------------------------------------------------
class Rect : public Shape {
	int w, h;	// 사각형의 가로와 세로 길이 (시작점은 p임)
public:
	Rect(int x = 0, int y = 0, int ww = 0, int hh = 0)
		: Shape(x, y), w(ww), h(hh) { }
	void draw(Canvas& canvas, string color = "■") {
		for (int i = p.x; i <= p.x + w; i++) {
			canvas.draw(i, p.y, color);	// 사각형의 윗변
			canvas.draw(i, p.y + h, color);	// 사각형의 아랫변
		}
		for (int i = p.y; i <= p.y + h; i++) {
			canvas.draw(p.x, i, color);	// 사각형의 좌변
			canvas.draw(p.x + w, i, color);	// 사각형의 우변
		}
	}
};
class Square : public Rect {
public:
	Square(int x = 0, int y = 0, int w = 0) : Rect(x, y, w, w) { }
};

// 원 클래스 ----------------------------------------------------------------------------
class Circle : public Shape {
	int r;		// 원의 반지름 (중심은 p를 사용)
public:
	Circle(int x = 0, int y = 0, int rr = 0)
		: Shape(x, y), r(rr) { }
	void draw(Canvas& canvas, string color = "◎") {
		Line(p.x, p.y, p.x, p.y + r).draw(canvas, color);
		Line(p.x, p.y, p.x, p.y - r).draw(canvas, color);
		Line(p.x, p.y, p.x + r, p.y).draw(canvas, color);
		Line(p.x, p.y, p.x - r, p.y).draw(canvas, color);
	}
};