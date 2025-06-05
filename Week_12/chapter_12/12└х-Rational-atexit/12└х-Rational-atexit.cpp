#include "Rational.h"

void onExit() { cout << "프로그램이 종료됩니다!" << endl; }
void main() 
{
	atexit(onExit);
	Rational r;
	cout << "r 입력(a/b): ";
	cin >> r;
	cout << "r = " << r << " = " << r.real() << endl;
}
