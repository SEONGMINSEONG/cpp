#include "myFunctions.h"	// 프로그램 3.7 포함
#include <stdio.h>
#include <time.h>

void main()
{
	clock_t t1 = clock();
	int score = playUpAndDown(43, 0, 99);
	clock_t t2 = clock();
	double  duration = (double)(t2 - t1) / CLOCKS_PER_SEC;

	printf(" 게임 점수: %d점\n", score);
	printf(" 걸린 시간: %lf초\n", duration);
}