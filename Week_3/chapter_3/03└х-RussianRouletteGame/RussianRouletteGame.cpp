#include "RussianRoulette.h"
void main()
{
	int nTurn, nBullets;
	srand((unsigned)time(NULL));

	printf("게임 인원 (예:2) ==> ");
	scanf("%d", &nTurn);
	printf("총알 개수 (6미만) ==> ");
	scanf("%d", &nBullets);
	getchar();

	int bang = playRussianRoulette(nTurn, nBullets);
	printf("\n -----> %d번 참가자가 총에 맞았습니다.\n", bang);
}