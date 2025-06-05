#include <iostream>
using namespace std;

struct NegBotException {
	int top, bottom;
	NegBotException(int t = 0, int b = 1) : top(t), bottom(b) {}
};

class Rational
{
	int top, bottom;
public:
	Rational(int t = 0, int b = 1) : top(t), bottom(b) { }
	double real() {
		if (bottom == 0) throw('E');
		return (double)top / bottom;
	}
	friend ostream& operator<<(ostream& os, const Rational& f) {
		os << f.top << "/" << f.bottom;
		return os;
	}
	friend istream& operator >> (istream& is, Rational& f) {
		is >> f.top >> f.bottom;		// 분자 / 분모 읽기
		if (f.bottom == 0) throw('E');
		if (f.bottom < 0) throw(NegBotException(f.top, f.bottom));
		return is;
	}
};
