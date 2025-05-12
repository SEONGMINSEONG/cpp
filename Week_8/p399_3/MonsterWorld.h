#pragma once
#include "Canvas.h"
#include "Monster.h"
#include "Matrix.h"
#include <unistd.h>
#include <iostream>
#define DIM 40
#define MAXMONS 5

class MonsterWorld {
private:
    int map[DIM][DIM];
    int xMax, yMax, nMon, nMove;
    Monster mon[MAXMONS];
    Canvas canvas;

    int& Map(int x, int y) { return map[y][x]; }
    bool isDone() { return countItems() == 0 || nMon == 0; }
    int countItems() {
        int nItems = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) nItems++;
        return nItems;
    }

    void print() {
        canvas.clear(". ");
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) canvas.draw(x, y, "O");
        for (int i = 0; i < nMon; i++)
            mon[i].draw(canvas);
        canvas.print("[ Monster World (몬스터의 세계) ]");

        std::cerr << " 총 이동 횟수 = " << nMove << std::endl;
        std::cerr << " 남은 아이템 수 = " << countItems() << std::endl;
        std::cerr << " 살아있는 몬스터 수 = " << nMon << std::endl;
        for (int i = 0; i < nMon; i++)
            std::cerr << "\t" << mon[i].getName() << mon[i].getIcon() << ": 아이템=" << mon[i].getItemCount() << ", 에너지=" << mon[i].getEnergyCount() << std::endl;
    }

    void checkStarvation() {
        for (int i = 0; i < nMon; ++i) {
            if (mon[i].getEnergyCount() <= 0) {
                std::cerr << mon[i].getName() << "(" << mon[i].getIcon() << ") 몬스터가 굶어 죽었습니다!" << std::endl;
                mon[i] = mon[nMon - 1];
                nMon--;
                i--;
            }
        }
    }

public:
    MonsterWorld(int w, int h) : canvas(w, h), xMax(w), yMax(h) {
        nMon = 0;
        nMove = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++) Map(x, y) = 1;
    }
    ~MonsterWorld() { }

    void add(Monster& m) {
        if (nMon < MAXMONS) {
            mon[nMon++] = m;
        }
    }

    void play(int maxwalk, int wait) {
        print();
        std::cerr << " 몬스터 이동 시작..." << std::endl;
        getchar();
        for (int i = 0; i < maxwalk; i++) {
            for (int k = 0; k < nMon; k++)
                mon[k].move(map, xMax, yMax);
            nMove++;
            checkStarvation();
            print();
            if (isDone()) break;
            usleep(wait * 1000);
        }
    }

    int getMonsterCount() const {
        return Monster::getMonsterCount();
    }
};