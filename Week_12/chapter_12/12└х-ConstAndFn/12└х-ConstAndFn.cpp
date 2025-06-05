#include <iostream>
using namespace std;

class Rational
{
	int top, bottom;
public:
	Rational(int t = 0, int b = 1) : top(t), bottom(b) { }
	double real() const {
		// (1) top = 2; bottom += 10;
		return (double)top / bottom;
	}
	friend ostream& operator<<(ostream& os, const Rational& f) {
		// (2) f.bottom = 10;
		os << f.top << "/" << f.bottom;
		return os;
	}
	friend istream& operator >> (istream& is, Rational& f) /* (3) const */ {
		is >> f.top >> f.bottom;
		return is;
	}
	Rational operator+(const Rational& f) const {
		// (4) top = 10; f.bottom = 20;
		return Rational(top*f.bottom + f.top*bottom, bottom*f.bottom);
	}
};
void main()
{
	Rational a(3, 4), b, c;
	const Rational h(1, 2);

	cout << "b ют╥б(a/b): ";
	cin >> b;
	// (5) cin >> h;
	c = a + b;
	cout << " a  = " << a << endl;
	cout << " b  = " << b << endl;
	cout << " h  = " << h << endl;
	cout << "a+b = " << c << endl;
}