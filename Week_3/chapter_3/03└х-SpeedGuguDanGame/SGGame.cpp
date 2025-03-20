#include "SpeedGugu.h"
void main()
{
	srand((unsigned)time(NULL));

	int nPlay = 10;
	printf("[스피드 구구단 게임]\n\n");
	printf(" 당신의 구구단 실력을 테스트하세요.!!!\n");
	printf(" %d번 테스트 하겠습니다.\n", nPlay);
	printf(" 크게 심호흡을 하시고...\n 준비되면 엔터를 누르세요...");
	getchar();
	system("cls");

	double score = playSpeedGugu(nPlay);
	printf("\n점수 = %4.1f점(총 %4.1f초)\n", score, tElapsed);
}