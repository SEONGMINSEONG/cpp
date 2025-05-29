#include "Rational.h"

void main()
{
	Rational a(4), b(6, 8), c, d;

	c[0] = 3;
	c(1) = 4;
	cout << "a     = " << a << " = " << (double)a << endl;
	cout << "b     = " << b << " = " << (double)b << endl;
	cout << "c     = " << c << " = " << (double)c << endl;
	cout << "d ют╥б(top bottom) : ";
	cin >> d;
	cout << "d     = " << d << endl;
	cout << "a++   = " << a++ << endl;
	cout << "   a  = " << a << endl;
	cout << "++b   = " << ++b << endl;
	cout << "  b   = " << b << endl;
}