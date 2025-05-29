#include <cstdio>

class Complex
{
	double	real;
	double	imag;
public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {  }
	void print(char* msg = "복소수 = ") {
		printf("  %s %4.2f + %4.2fi\n", msg, real, imag);
	}

	// 산술 단항 - : -c(부정, negation)
	Complex operator-() { return Complex(-real, -imag); }
	// 산술 단항 ~ : ~c 켤레 복소수 (의미가 애매하므로 중복하지 않는 것이 더 좋음)
	Complex operator~() { return Complex(real, -imag); }

	// 산술 이항 - : a - b
	Complex operator-(Complex b) {
		return Complex(real - b.real, imag - b.imag);
	}
	// 산술 * : 복소수와 스칼라의 곱. c*s와 s*c 연산이 각각 다른 연산자에 의해 처리됨
	Complex operator*(double s) { return Complex(s*real, s*imag); }
	friend Complex operator*(double s, Complex c) {	// 일반 함수임 !!! 
		return Complex(s*c.real, s*c.imag);
	}

	// 비교 : c1 == c2, c1 != c2
	bool operator==(Complex a) { return real == a.real && imag == a.imag; }
	bool operator!=(Complex a) { return real != a.real || imag != a.imag; }
	// 다른 비교 연산자 >, <, >=, <=, 등은 개념이 애매함. 중복하지 않는 것이 바람직함.

	// 대입 : c1=c2, c1+=c2, c1-=c2
	Complex& operator=(Complex a) { real = a.real; imag = a.imag; return *this; }
	Complex& operator+=(Complex a) { real += a.real; imag += a.imag; return *this; }
	Complex& operator-=(Complex a) { real -= a.real; imag -= a.imag; return *this; }
	// 다른 대입 연산자 <<=, >>=, 등도 개념이 애매함. 중복하지 않는 것이 바람직함.
};

void main()
{
	Complex c1(1, 2), c2(3, 4), c3, c4, c5, c6, c7, c8;

	c1.print("c1(1, 2)      : ");
	c2.print("c2(3, 4)      : ");
	c3 = -c1;
	c3.print("c3 = -c1      : ");
	c4 = ~c1;
	c4.print("c4 = ~c1      : ");
	c5 = c1 - c2;
	c5.print("c5 = c1 - c2  : ");
	c5 = c1 * 2.0;
	c5.print("c5 = c1 * 2.0 : ");
	c6 = 3.0 * c1;
	c6.print("c6 = 3.0 * c1 : ");
	c7 = c8 = c1;
	c7.print("c7 = c8 = c1  : ");
	c7 += c1;
	c7.print("c7 += c1      : ");
	c8 -= c1;
	c8.print("c8 -= c1      : ");
}
