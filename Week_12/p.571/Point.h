#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Point {
    int x, y;
    friend class Monster;
    friend class Canvas;
public:
    Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
    int& operator[] (int id) {
        if (id == 0) return x;
        else if (id == 1) return y;
        else exit(0);
    }
    operator double() { return sqrt((double)x*x + y*y); }
    void operator()(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }
    Point operator- () { return Point(-x, -y); }
    bool operator== (Point &p) { return x == p.x && y == p.y; }
    bool operator!= (Point &p) { return x != p.x || y != p.y; }
    Point operator- (Point &p) { return Point(x - p.x, y - p.y); }
    Point operator+ (Point &p) { return Point(x + p.x, y + p.y); }
    void operator+= (Point &p) { x += p.x, y += p.y; }
    void operator-= (Point &p) { x -= p.x, y -= p.y; }
};