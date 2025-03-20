#include "RussianRoulette.h"
int playRussianRoulette(int nTurns, int nBullets)
{
	int start = rand() % nTurns;
	printf("\n총을 돌렸습니다. %d번부터 시작합니다.\n", start + 1);
	while (true) {
		int pos = rand() % 6;
		printf("[%d번]\t탄창을 무작위로 돌렸습니다.\n", start + 1);
		printf("\t엔터를 누르면 격발됩니다...");
		getchar();
		if (pos < nBullets) break;
		printf("\t휴~~~ 살았습니다!!!\n");
		start = (start + 1) % nTurns;
	}
	printf("\t빵~~~~~~~~~!!!\n");
	return start + 1;
}