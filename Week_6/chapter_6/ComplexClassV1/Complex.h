#pragma once
#include <cstdio>

class Complex
{
	double	real;
	double	imag;
public:
	void setComplex( double r, double i ) {
		real = r;
		imag = i;
	}
	void	readComplex( char* msg = " 복소수 =" );
	void	printComplex( char* msg = "복소수 = " );
	void	addComplex ( Complex a, Complex b );
};
