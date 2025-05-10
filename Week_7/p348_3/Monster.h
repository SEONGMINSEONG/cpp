#pragma once
#include "Canvas.h"
#include <string>
#define DIM 40

// 몬스터의 속성과 동작을 관리
class Monster {
    std::string name, icon; // 몬스터 이름과 화면 출력용 아이콘
    int x, y, nItem;       // 몬스터 위치와 아이템 개수
    int nEnergy;           // 몬스터 에너지

    void clip(int maxx, int maxy) { // 역할: 몬스터 위치를 캔버스 범위 내로 제한
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int map[DIM][DIM]) { // 역할: 현재 위치의 아이템을 먹고 에너지 관리
        if (x >= 0 && x < DIM && y >= 0 && y < DIM) {
            if (map[y][x] == 1) {
                map[y][x] = 0;
                nItem++;
                nEnergy += 8; // 아이템을 먹으면 에너지 8 증가
            } else {
                nEnergy--; // 아이템을 먹지 못하면 에너지 1 감소
                if (nEnergy < 0) nEnergy = 0; // 에너지 최솟값은 0
            }
        }
    }
public:
    Monster(std::string n = "몬스터", std::string i = "*", int px = 0, int py = 0) // 역할: 몬스터 객체를 초기화
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {
        clip(DIM, DIM); // 생성 시 좌표 검증
    }
    ~Monster() { } // 역할: Monster 객체 소멸 (현재 비어 있음)

    void draw(Canvas &canvas) { // 역할: 몬스터를 캔버스에 그림
        canvas.draw(x, y, icon);
    }

    void move(int map[DIM][DIM], int maxx, int maxy) { // 역할: 몬스터를 무작위로 이동시키고 아이템 먹기
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
    void print() { // 역할: 몬스터의 상태(이름, 아이콘, 아이템 수, 에너지)를 출력
        std::cout << "\t" << name << icon << ": 아이템=" << nItem << ", 에너지=" << nEnergy << std::endl;
    }
};