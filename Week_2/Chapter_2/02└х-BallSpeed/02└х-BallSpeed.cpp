#include <stdio.h>
const double RateKphMph = 1.609344;
void main()
{
	int kph;
	double mph;

	printf("당신의 구속을 입력하시오[Km/H]: ");
	scanf("%d", &kph);
	mph = kph / RateKphMph;
	printf("당신의 구속은 %lf [MPH] 입니다.\n", mph);
}