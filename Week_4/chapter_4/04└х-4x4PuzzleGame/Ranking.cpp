#include "Ranking.h"
#define NUM_MVP 5
static PlayInfo MVP[NUM_MVP];	// 랭킹 배열
static int nMVP = NUM_MVP;	// 랭킹 배열의 길이

static void initRanking() {
	PlayInfo noname = { "C++좋아요", 1000, 1000.0 };
	for (int i = 0; i<nMVP; i++)
		MVP[i] = noname;
}
void loadRanking(char* fname) {
	FILE* fp = fopen(fname, "r");
	if (fp == NULL)
		initRanking();
	else {
		for (int i = 0; i<nMVP; i++)
			fscanf(fp, "%d%s%lf", &MVP[i].nMove,
				MVP[i].name, &MVP[i].tElapsed);
		fclose(fp);
	}
}
void storeRanking(char* fname) {
	FILE* fp = fopen(fname, "w");
	if (fp == NULL) return;
	for (int i = 0; i<nMVP; i++)
		fprintf(fp, "  %4d  %-16s %-5.1f\n", MVP[i].nMove,
			MVP[i].name, MVP[i].tElapsed);
	fclose(fp);
}
void printRanking() {
	for (int i = 0; i<nMVP; i++)
		printf("  [%2d위]  %4d  %-16s %5.1f\n", i + 1, MVP[i].nMove,
			MVP[i].name, MVP[i].tElapsed);
}
int addRanking(int nMove, double tElap) {
	if (nMove < MVP[nMVP - 1].nMove) {
		int pos = nMVP - 1;
		for (; pos>0; pos--) {
			if (nMove >= MVP[pos - 1].nMove) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;
		MVP[pos].tElapsed = tElap;
		printf(" %d위입니다. 이름을 입력하세요: ", pos + 1);
		scanf("%s", MVP[pos].name);
		return pos + 1;
	}
	return 0;
}