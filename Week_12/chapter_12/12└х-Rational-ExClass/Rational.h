#pragma once
#include <iostream>
#include <string>
using namespace std;

struct NegBotException {
	int top, bottom;
	NegBotException(int t = 1, int b = 0) : top(t), bottom(b) {}
};

class Rational
{
	int top;		// 유리수의 분자
	int bottom;	// 유리수의 분모(0이 아니어야 함)
public:
	double real() {
		try {
			if (bottom < 0)
				throw(NegBotException(top, bottom));
		}
		catch (NegBotException e) {
			cout << "예외 발생: 분모가 음수입니다. "
				<< -e.top << '/' << -e.bottom << "이 바람직합니다.\n";
		}

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