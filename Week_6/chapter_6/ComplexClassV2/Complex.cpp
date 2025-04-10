#include "Complex.h"

void Complex::read( char* msg )
{
	printf("  %s ", msg);
	scanf("%lf%lf", &real, &imag);
}
void Complex::print( char* msg )
{
	printf("  %s %4.2f + %4.2fi\n", msg, real, imag);
}

// 더하기 / 빼기 등의 멤버함수 추가
void Complex::add( Complex a, Complex b )
{
	real = a.real + b.real;
	imag = a.imag + b.imag;
}