#pragma once
#include "Canvas.h"
#include "Monster.h"
#include <unistd.h>
#include <iostream>
#define DIM 40
#define MAXMONS 5

// 게임의 전체 로직을 관리
class MonsterWorld {
    int map[DIM][DIM];
    int xMax, yMax, nMon, nMove;
    Monster mon[MAXMONS];
    Canvas canvas;

    int& Map(int x, int y) { return map[y][x]; } // 역할: 맵의 (x, y) 위치를 참조
    bool isDone() { return countItems() == 0; } // 역할: 모든 아이템이 먹혔는지 확인하여 게임 종료 조건 반환
    int countItems() {                         // 역할: 맵에 남은 아이템 수를 계산
        int nItems = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) nItems++;
        return nItems;
    }

    void print() {                             // 역할: 현재 게임 상태(캔버스, 이동 횟수, 아이템 수, 몬스터 상태)를 출력
        canvas.clear(". "); // 캔버스 점으로 초기화
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) canvas.draw(x, y, "O"); // 아이템만 O
        for (int i = 0; i < nMon; i++)
            mon[i].draw(canvas);
        canvas.print("[ Monster World (몬스터의 세계) ]");

        std::cerr << " 총 이동 횟수 = " << nMove << std::endl;
        std::cerr << " 남은 아이템 수 = " << countItems() << std::endl;
        for (int i = 0; i < nMon; i++)
            mon[i].print();
    }
public:
    MonsterWorld(int w, int h) : canvas(w, h), xMax(w), yMax(h) { // 역할: 게임을 지정된 크기(w x h)로 초기화
        nMon = 0;
        nMove = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++) Map(x, y) = 1;
    }
    ~MonsterWorld() { } // 역할: MonsterWorld 객체 소멸 (현재 비어 있음)

    void add(Monster& m) { // 역할: 몬스터를 게임에 추가
        if (nMon < MAXMONS) mon[nMon++] = m;
    }

    void play(int maxwalk, int wait) { // 역할: 게임을 실행하며 몬스터 이동과 상태 업데이트
        print();
        std::cerr << " 몬스터 이동 시작...";
        getchar();
        for (int i = 0; i < maxwalk; i++) {
            for (int k = 0; k < nMon; k++)
                mon[k].move(map, xMax, yMax);
            nMove++;
            print();
            if (isDone()) break;
            usleep(wait * 1000);
        }
    }
};