#include <stdio.h>
void main()
{
	// 절차적 프로그래밍
	int i = 1;
	int dan = 3;
	printf("[절차적 프로그래밍]\n");
	printf("[구구단 %d 단]\n", dan);
loop:
	printf("%2d x %2d = %2d\n", dan, i, dan*i);
	i++;
	if (i <= 9) goto loop;
}