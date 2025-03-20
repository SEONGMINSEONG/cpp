#include <stdio.h>
#include <math.h>					// pow()를 사용하기 위해 포함
double myPow(double x, int y) {	// 사용자 정의 함수
	double result = 1.0;
	for (int i = 0; i<y; i++)
		result = result * x;
	return result;
}
void main()
{
	printf("라이브러리 pow(2.0, 5) = %lf\n", pow(2.0, 5));
	printf("내가만든 myPow(2.0, 5) = %lf\n", myPow(2.0, 5));
}