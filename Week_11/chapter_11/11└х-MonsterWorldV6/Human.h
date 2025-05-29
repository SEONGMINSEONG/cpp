#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
public:
	Human(string n = "미래인류", string i = "♀", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human   ]"; }
	int getDirKey() { return getche() == 224 ? getche() : 0; }
	void move(int** map, int maxx, int maxy) {
		if (kbhit()) {
			char ch = getDirKey();
			if (ch == Left) p[0]--;
			else if (ch == Right) p[0]++;
			else if (ch == Up) p[1]--;
			else if (ch == Down) p[1]++;
			else return;

			clip(maxx, maxy);
			eat(map);
		}
	}
};