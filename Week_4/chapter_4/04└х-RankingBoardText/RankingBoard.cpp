#include "Ranking.h"
#include <stdlib.h>
#include <time.h>
void main()
{
	srand((unsigned int)time(NULL));
	loadRanking("ranking.txt");
	printRanking();

	for (int i = 0; i < 5; i++)
		addRanking(rand() % 500, rand() % 1000 * 0.1);
	storeRanking("ranking.txt");
}