#pragma once
#include "Canvas.h"
#include <string>
#define DIM 40

class Monster {
private: // 차이점: 접근 제한자 private/public 명시적으로 추가
    std::string name, icon;
    int x, y, nItem;
    int nEnergy;
    static int monsterCount; // 차이점: 몬스터 수를 추적하기 위해 정적 멤버 변수 monsterCount 추가

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int map[DIM][DIM]) {
        if (x >= 0 && x < DIM && y >= 0 && y < DIM) {
            if (map[y][x] == 1) {
                map[y][x] = 0;
                nItem++;
                nEnergy += 8;
            } else {
                nEnergy--;
                if (nEnergy < 0) nEnergy = 0;
            }
        }
    }
public:
    Monster(std::string n = "몬스터", std::string i = "*", int px = 0, int py = 0, int energy = 100)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(energy) { // 차이점: energy 매개변수 추가, nEnergy를 동적으로 초기화
        clip(DIM, DIM);
        monsterCount++; // 차이점: 생성 시 몬스터 수 증가
    }
    ~Monster() {
        monsterCount--; // 차이점: 소멸 시 몬스터 수 감소
    }

    void draw(Canvas &canvas) {
        canvas.draw(x, y, icon);
    }

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
        std::cout << "\t" << name << icon << ": 아이템=" << nItem << ", 에너지=" << nEnergy << std::endl;
    }

    int getEnergy() const { // 에너지 값을 반환하는 Getter (접근자) 함수
        return nEnergy; // 몬스터의 현재 에너지 값을 반환
    }

    std::string getName() const { // 몬스터의 이름을 반환하는 Getter (접근자) 함수
        return name; // 몬스터의 이름을 반환
    }

    std::string getIcon() const { // 몬스터의 아이콘을 반환하는 Getter (접근자) 함수
        return icon; // 몬스터의 아이콘을 반환
    }

    int getItemCount() const { // 몬스터가 획득한 아이템 개수를 반환하는 Getter (접근자) 함수
        return nItem; // 몬스터가 가진 아이템 수를 반환
    }

    int getEnergyCount() const { // 몬스터의 에너지 값을 반환하는 Getter (접근자) 함수 (getEnergy와 기능 중복)
        return nEnergy; // 몬스터의 현재 에너지 값을 반환
    }

    static void printCount() { // 현재까지 생성된 총 몬스터 수를 출력하는 정적(static) 함수
        std::cout << "현재 몬스터 수: " << monsterCount << std::endl; // 클래스 변수인 monsterCount 값을 출력
    }

    static int getMonsterCount() { // 현재까지 생성된 총 몬스터 수를 반환하는 정적(static) 함수
        return monsterCount; // 클래스 변수인 monsterCount 값을 반환
    }
};

int Monster::monsterCount = 0; // 정적(static) 멤버 변수 monsterCount를 0으로 초기화 (프로그램 시작 시 한 번 실행)