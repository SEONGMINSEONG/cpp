#include "Complex.h"

void main()
{
	Complex a, b, c, d, e;

	a.read ( "A =" );
	b.read ( "B =" );
	c.add(a,b);		// add() 함수의 다른 구현
//	c = a.add(b);		// add() 함수의 다른 구현
//	d = a + b;			// 연산자 오버로딩
//	e = a.operator+(b);	// 연산자 오버로딩

	a.print ( "    A     = ");
	b.print ( "    B     = ");
	c.print ( "C.add(A,B)= ");
//	d.print ( "D=A+B           = ");
//	e.print ( "E=A.operator(B) = ");
}