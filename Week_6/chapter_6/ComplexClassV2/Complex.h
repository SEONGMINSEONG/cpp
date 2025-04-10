#pragma once
#include <cstdio>

// 복소수 클래스 선언
class Complex
{
	double	real;
	double	imag;
public:
	// 복소수 내용을 설정하는 함수 : inline
	void set( double r, double i ) {
		real = r;
		imag = i;
	}
	void	read( char* msg = " 복소수 입력 =" );
	void	print( char* msg = "복소수 = " );
	void	add( Complex a, Complex b );
};
