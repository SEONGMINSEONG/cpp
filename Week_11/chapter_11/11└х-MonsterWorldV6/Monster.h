#pragma once
#include "Canvas.h"
#include "Point.h"

class Monster {
protected:
	string name, icon; 	// 몬스터 이름과 화면 출력용 아이콘
	int nItem;		// 먹은 아이템 수
	Point q, p;		// 추가: 이전 위치(q)와 현재 위치(p)
	int nSleep;		// 추가: 쉬어야 하는 횟수
	double dist;		// 추가: 쉬고 난 다음 움직인 거리
	double total;		// 추가: 총 움직인 거리

	void clip(int maxx, int maxy) { p(maxx, maxy); }
	void eat(int** map) {
		if (map[p.y][p.x] == 1) {
			map[p.y][p.x] = 0;
			nItem++;
		}
		dist += (double)(p - q);
		total += (double)(p - q);
		q = p;
		if (dist > 20) {
			dist = 0;
			nSleep = 10;
		}
	}
	bool isSleep() {
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		else return false;
	}
public:
	Monster(string n = "무명괴물", string i = "※", int x = 0, int y = 0)
		: name(n), icon(i), nItem(0),
		p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {}
	virtual ~Monster() { cout << icon << nItem << "거리:" << total << endl; }

	void draw(Canvas &canvas) { canvas.draw(p, icon); }
	virtual void move(int** map, int maxx, int maxy) {
		if (!isSleep()) {
			int num = rand() % 9 + 1;	// 1 ~ 9
			p += Point(num % 3 - 1, num / 3 - 1);
			clip(maxx, maxy);
			eat(map);
		}
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl; }
};