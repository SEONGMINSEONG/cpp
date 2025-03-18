#include <stdio.h>
void main()
{
	float f;
	long int i;
	long double d;

	printf("<자료형의 크기 [bytes]>\n");
	printf("   char 형 = %d\n", sizeof(char));
	printf("  short 형 = %d\n", sizeof(short));
	printf("    int 형 = %d\n", sizeof(int));
	printf("   long 형 = %d\n", sizeof(long));
	printf("  float 형 = %d\n", sizeof(float));
	printf(" double 형 = %d\n", sizeof(double));

	printf("\n<변수의 크기 [bytes]>\n");
	printf("   long int 변수 = %d\n", sizeof(i));
	printf("      float 변수 = %d\n", sizeof(f));
	printf("long double 변수 = %d\n", sizeof(d));

	printf("\n<상수나 연산 결과>\n");
	printf("  '3'의 자료형 = %d\n", sizeof('3'));
	printf("   3 의 자료형 = %d\n", sizeof(3));
	printf(" 3.0 의 자료형 = %d\n", sizeof(3.0));
	printf("3.0f 의 자료형 = %d\n", sizeof(3.0f));
	printf(" 3+4 의 자료형 = %d\n", sizeof(3 + 4));
	printf("3.0+4의 자료형 = %d\n", sizeof(3.0 + 4));
}