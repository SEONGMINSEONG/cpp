#include "Rational.h"

void main()
{
	Rational r;
	cout << "r 입력(a/b): ";
	try {
		cin >> r;
	}
	catch (char c) {
		cout << "예외 발생: 분수에서 분모가 0입니다.\n";
		cout << "더 진행할 수 없습니다.\n";
		exit(0);
	}
	catch (NegBotException e) {
		r = Rational(-e.top, -e.bottom);
		cout << "예외 발생: 분모를 양수로 변환합니다.\n";
	}
	cout << "r = " << r << endl;
	cout << "r = " << r.real() << endl;
}