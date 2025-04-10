#include <stdio.h>
#define NUM_MVP 5
struct PlayInfo {
	char	name[200];
	int	nMove;
	double 	tElapsed;
};
class RankingBoard {
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;		// VS2013:OK, VS2010:Error
	void init() {  			// initRanking()과 동일
		PlayInfo noname = { "C++좋아요", 1000, 1000.0 };
		for (int i = 0; i<nMVP; i++)
			MVP[i] = noname;
	}

public:
	RankingBoard() : nMVP(NUM_MVP) {} 	// VS2010 이하인 경우 추가
	void load(char* fname) { 		// loadRanking()과 동일
		FILE* fp = fopen(fname, "r");
		if (fp == NULL)
			init();
		else {
			for (int i = 0; i<nMVP; i++)
				fscanf(fp, "%d%s%lf", &MVP[i].nMove,
					MVP[i].name, &MVP[i].tElapsed);
			fclose(fp);
		}
	}
	void store(char* fname) {  		// storeRanking()과 동일
		FILE* fp = fopen(fname, "w");
		if (fp == NULL) return;
		for (int i = 0; i<nMVP; i++)
			fprintf(fp, "  %4d  %-16s %-5.1f\n", MVP[i].nMove,
				MVP[i].name, MVP[i].tElapsed);
		fclose(fp);
	}
	void print() {  			// printRanking()과 동일
		for (int i = 0; i<nMVP; i++)
			printf("  [%2d위]  %4d  %-16s %5.1f\n", i + 1, MVP[i].nMove,
				MVP[i].name, MVP[i].tElapsed);
	}
	int add(int nMove, double tElap) { 	// addRanking()과 동일
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
};