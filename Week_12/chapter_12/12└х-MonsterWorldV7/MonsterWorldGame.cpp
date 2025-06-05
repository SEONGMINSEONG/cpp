#include "MonsterWorld.h"
#include "Human.h"
#include "RankingBoard.h"
#include <time.h>

void main()
{
	RankingBoard rank;
	try {
		rank.load("MonsterWorld.rnk");
	}
	catch (FileException e) {
		char str[80];
		string passwd, correct = "123456";
		cout << "관리자 비밀번호를 입력하세요: ";
		for (int i = 0;; i++) {
			str[i] = getch();
			putchar('*');
			if (str[i] == '\r') {
				str[i] = '\0';
				passwd = str;
				cout << "\n";
				break;
			}
		}
		if (passwd != correct) {
			cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
			exit(0);
		}
		// 비밀 번호가 맞으면 기본 랭킹으로 게임을 계속 진행함.
	}
	rank.print("[게임 랭킹: 시작]");

	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);
	game.add(new Zombie("허접한좀비", "§", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));

	Human* human = new Human("미래의인류", "♀", rand() % w, rand() % h);
	game.add(human);
	game.play(500, 10);
	printf("------게임 종료-------------------\n");

	rank.add(human->nItem, human->nItem / human->total);
	rank.print("[게임 랭킹: 종료]");
	rank.store("MonsterWorld.rnk");
}