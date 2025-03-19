#include <stdio.h>

void main()
{
	int		i;
	double	d;
	char 	str[100];

	printf("정수 입력: ");
	scanf("%d", &i);
	printf(" - 입력된 정수: %d\n", i);
	printf(" - 정수 변수의 주소: %0x\n\n", &i);

	printf("실수 입력: ");
	scanf("%lf", &d);
	printf(" - 입력된 실수: %lf\n", d);
	printf(" - 실수 변수의 주소: %0x\n\n", &d);

	printf("문자열 입력: ");
	scanf("%s", str);
	printf(" - 입력된 문자열: %s\n", str);
	printf(" - 문자열의 주소: %0x\n", str);
}