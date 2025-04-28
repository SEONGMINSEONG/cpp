#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
    string name, icon;  // 몬스터 이름과 화면 출력용
    int x, y, nItem;    // 몬스터 위치와 먹은 아이템 수
    int nEnergy;        // 몬스터 에너지 (추가된 속성)

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }
    void eat(int map[DIM][DIM]) {
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            nEnergy += 8;  // 아이템 먹으면 에너지 8 증가
        }
        else {
            nEnergy -= 1;  // 아이템 못 먹으면 에너지 1 감소
            if (nEnergy < 0) nEnergy = 0;  // 에너지 최솟값 0
        }
    }
public:
    Monster(string n = "몬스터", string i = "★", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}  // 에너지 100으로 초기화
    ~Monster() { cout << "\t" << name << icon << " 소멸되었습니다~~~\n"; }

    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
    void move(int map[DIM][DIM], int maxx, int maxy) {
        switch (rand() % 8) {
        case 0: y--; break;
        case 1: x++; y--; break;
        case 2: x++; break;
        case 3: x++; y++; break;
        case 4: y++; break;
        case 5: x--; y++; break;
        case 6: x--; break;
        case 7: x--; y--; break;
        }
        clip(maxx, maxy);
        eat(map);
    }
    void print() { 
        cout << "\t" << name << icon << ": " << nItem << " (Energy: " << nEnergy << ")\n"; 
    }
};