#include <stdio.h>
void main()
{
	int income;
	double tax = 0;
	printf("연봉을 입력하세요 ==> ");
	scanf("%d", &income);

	if (income <= 1200) {
		tax = income * 0.06;
	}
	if (1200<income  && income <= 4600) {
		tax = 1200 * 0.06 + (income - 1200) * 0.15;
	}
	if (4600<income  && income <= 8800) {
		tax = 1200 * 0.06 + (4600 - 1200)* 0.15 + (income - 4600)*0.24;
	}
	if (8800<income  && income <= 15000) {
		tax = 1200 * 0.06 + (4600 - 1200)* 0.15 + (8800 - 4600)*0.24 + (income - 8800)*0.35;
	}
	if (15000 < income) {
		tax = 1200 * 0.06 + (4600 - 1200)* 0.15 + (8800 - 4600)*0.24 + (15000 - 8800)*0.35 + (income - 15000)*0.38;
	}
	printf(" 전체세금은 %7.1f만원입니다.\n", tax);
	printf(" 순수소득은 %7.1f만원입니다.\n", income - tax);
}