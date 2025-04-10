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
	void read( char* msg = " 복소수 입력 ="  ) {
		printf("  %s ", msg);
		scanf("%lf%lf", &real, &imag);
	}
	void print( char* msg = "복소수 = "  ) {
		printf("  %s %4.2f + %4.2fi\n", msg, real, imag);
	}

	// 더하기 / 빼기 등의 멤버함수 추가
	void add( Complex a, Complex b ) {
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}
	/*
	// 더하기 / 빼기 등의 멤버함수 추가
	Complex add( Complex b ) {
		Complex c;
		c.real = real + b.real;
		c.imag = imag + b.imag;
		return c;
	}
	
	Complex operator+( Complex b ) { return add(b); }
	*/
};
