#pragma once
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Rational
{
	int top;		// 유리수의 분자
	int bottom;	// 유리수의 분모(0이 아니어야 함)
public:
	double real() {
		assert(bottom != 0);
		return (double)top / bottom;
	}

	Rational(int t = 0, int b = 1) : top(t), bottom(b) { }
	Rational& operator++() { top += bottom; return *this; }
	Rational operator++(int) {
		top += bottom;
		return Rational(top - bottom, bottom);
	}
	friend ostream& operator<<(ostream& os, const Rational& f) {
		os << f.top << "/" << f.bottom;
		return os;
	}
	friend istream& operator >> (istream& is, Rational& f) {
		is >> f.top >> f.bottom;
		return is;
	}
	operator double() { return (double)top / bottom; }
	int& operator[](int id) {
		if (id == 0) return top;
		else if (id == 1) return bottom;
		else exit(0);
	}
	int& operator()(int id) { return (*this)[id]; }
};