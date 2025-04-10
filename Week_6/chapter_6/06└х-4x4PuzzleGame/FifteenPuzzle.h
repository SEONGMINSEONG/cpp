#include "RankingBoard.h"	// 프로그램 6.3의 랭킹 처리 클래스 포함
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define DIM  4
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
const int DirKey[4] = { Left, Right, Up, Down };

class FifteenPuzzle {
	int	map[DIM][DIM];
	int	x, y;
	int	nMove;
	clock_t	tStart;
	RankingBoard	ranking;

	void init() { 			// init()와 동일
		for (int i = 0; i<DIM*DIM - 1; i++)
			map[i / DIM][i%DIM] = i + 1;
		map[DIM - 1][DIM - 1] = 0;
		x = DIM - 1; y = DIM - 1;

		srand(time(NULL));	// 난수 발생 시작 설정
		tStart = clock();	// 기준 시각 설정
		nMove = 0;		// 이동 횟수 초기화
	}
	void display() { 			// display()와 동일
		system("cls");
		printf("\tFifteen Puzzle\n\t");
		printf("--------------\n\t");
		for (int r = 0; r<DIM; r++) {
			for (int c = 0; c<DIM; c++) {
				if (map[r][c]>0)
					printf("%3d", map[r][c]);
				else printf("   ");
			}
			printf("\n\t");
		}
		printf("--------------\n\t");
		clock_t	t1 = clock();
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
		printf("\n\t이동 횟수:%6d\n\t소요 시간:%6.1f\n\n", nMove, d);
	}
	bool move(int dir) { 		// move()와 동일
		if (dir == Right && x>0) {		// → : 맨 왼쪽 열인지 검사
			map[y][x] = map[y][x - 1];
			map[y][--x] = 0;
		}
		else if (dir == Left && x<DIM - 1) {	// ← : 맨 오른쪽열인지 검사
			map[y][x] = map[y][x + 1];
			map[y][++x] = 0;
		}
		else if (dir == Up && y<DIM - 1) {		// ↑ : 맨 아래행인지 검사
			map[y][x] = map[y + 1][x];
			map[++y][x] = 0;
		}
		else if (dir == Down && y>0) {		// ↓ : 맨 윗행인지 검사
			map[y][x] = map[y - 1][x];
			map[--y][x] = 0;
		}
		else return false;

		nMove++;
		return true;
	}
	void shuffle(int nShuffle) { 	// shuffle()와 동일
		for (int i = 0; i<nShuffle; i++) {
			int key = DirKey[rand() % 4];
			if (move(key) == false) { i--; continue; }
			display();
			Sleep(50);
		}
	}
	bool isDone() { 			// isDone()와 동일
		for (int r = 0; r<DIM; r++) {
			for (int c = 0; c<DIM; c++) {
				if (map[r][c] != r * DIM + c + 1)
					return (r == DIM - 1) && (c == DIM - 1);
			}
		}
		return true;
	}
	int getDirKey() { 			// getDirKey()와 동일
		return getche() == 224 ? getche() : 0;
	}
public:
	void play(char* filename) {
		ranking.load(filename);	// 게임이 시작되면 랭킹을 읽음 
		init();
		display();
		ranking.print();		// 현재 랭킹을 출력

		// 프로그램 4.14의 play()함수 내용 추가
		printf("\n 퍼즐을 섞어주세요(엔터)...");
		getche();
		shuffle(100);			// 퍼즐 조각을 100번 이동해 섞음
		printf("\n 게임이 시작됩니다...");
		getche();

		nMove = 0;			// 이동 횟수 초기화
		tStart = clock();		// 기준 시각을 재 설정
		while (!isDone()) {		// 게임 종료 검사
			move(getDirKey());	// 키를 받아 퍼즐조각 이동
			display();		// 현재 상태를 화면에 출력
		}
		clock_t	t1 = clock();		// 현재 시각
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;

		ranking.add(nMove, d);	// 랭킹에 게임 결과 추가
		ranking.store(filename);	// 현재 랭킹을 파일에 저장
	}

};
