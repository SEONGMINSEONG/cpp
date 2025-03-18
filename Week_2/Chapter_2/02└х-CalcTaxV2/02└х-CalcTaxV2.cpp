#include <stdio.h>
void main()
{
	int income, in;
	double tax = 0;
	printf("연봉을 입력하세요 ==> ");
	scanf("%d", &income);
	in = income;

	if (income > 15000) {
		tax += (income - 15000)*0.38;
		income = 15000;
	}
	if (income > 8800) {
		tax += (income - 8800)*0.35;
		income = 8800;
	}
	if (income > 4600) {
		tax += (income - 4600)*0.24;
		income = 4600;
	}
	if (income > 1200) {
		tax += (income - 1200)*0.15;
		income = 1200;
	}
	tax += income*0.06;
	printf(" 전체세금은 %7.1f만원입니다.\n", tax);
	printf(" 순수소득은 %7.1f만원입니다.\n", in - tax);
}