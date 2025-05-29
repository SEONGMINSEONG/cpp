#pragma once
#include "Canvas.h"
#include "VariousMonsters.h"
#include "Matrix.h"
#include <chrono>
#include <thread>
#include <ncurses.h>

#define MAXMONS 8

class MonsterWorld {
    Matrix world;
    int xMax, yMax, nMon, nMove;
    Monster* pMon[MAXMONS];
    Canvas canvas;

    int& Map(int x, int y) { return world.elem(x, y); }

    bool isDone() { return countItems() == 0; }

    int countItems() {
        int nItems = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) nItems += 10;
        return nItems / 10;
    }

    void checkStarvation() {
        for (int i = 0; i < nMon; ) {
            if (pMon[i]->getEnergy() <= 0) {
                printw("\t%s%s starved and removed!\n", pMon[i]->getName().c_str(), pMon[i]->getIcon().c_str());
                delete pMon[i];
                for (int j = i; j < nMon - 1; j++) {
                    pMon[j] = pMon[j + 1];
                }
                pMon[nMon - 1] = nullptr;
                nMon--;
            } else {
                i++;
            }
        }
    }

    void print() {
        canvas.clear();
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0)
                    canvas.draw(x, y, "O");
        for (int i = 0; i < nMon; i++)
            pMon[i]->draw(canvas);
        clear();
        printw("[ Monster World (All Monsters Moving) ]\n");
        canvas.print();
        printw("Total Moves = %d\n", nMove);
        Monster::printCount();
        printw("Remaining Items = %d\n", countItems());
        for (int i = 0; i < nMon; i++)
            pMon[i]->print();
        printw("Use WASD for Left Player (좌), Arrow Keys for Right Player (우)\n");
        refresh();
    }

public:
    MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h), nMon(0), nMove(0) {}

    ~MonsterWorld() {
        for (int i = 0; i < nMon; i++)
            delete pMon[i];
    }

    void add(Monster* m) {
        if (nMon < MAXMONS)
            pMon[nMon++] = m;
    }

    void play(int maxwalk, int wait) {
        printw("Press Enter to start... (Left Player: WASD for 좌, Right Player: Arrow Keys for 우)\n");
        refresh();
        getch();
        print();
        nodelay(stdscr, TRUE);
        timeout(100);
        for (int i = 0; i < maxwalk; i++) {
            int key = getch();
            if (key != ERR) {
                // ESC 시퀀스 처리 (화살표 키)
                if (key == 27) { // ESC
                    key = getch();
                    if (key == '[') { // ANSI 시퀀스
                        key = getch();
                        if (nMon > 1) {
                            if (key == 'A') dynamic_cast<Tuman*>(pMon[nMon-1])->moveHuman(world.Data(), xMax, yMax, KEY_UP); // Up
                            else if (key == 'B') dynamic_cast<Tuman*>(pMon[nMon-1])->moveHuman(world.Data(), xMax, yMax, KEY_DOWN); // Down
                            else if (key == 'D') dynamic_cast<Tuman*>(pMon[nMon-1])->moveHuman(world.Data(), xMax, yMax, KEY_LEFT); // Left
                            else if (key == 'C') dynamic_cast<Tuman*>(pMon[nMon-1])->moveHuman(world.Data(), xMax, yMax, KEY_RIGHT); // Right
                        }
                    }
                }
                // WASD: Left Player (Tuman, 좌)
                else if (nMon > 1 && (key == 'w' || key == 's' || key == 'a' || key == 'd')) {
                    dynamic_cast<Tuman*>(pMon[nMon-2])->moveHuman(world.Data(), xMax, yMax, key);
                }
                // Arrow Keys: Right Player (Tuman, 우)
                else if (nMon > 1 && (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)) {
                    dynamic_cast<Tuman*>(pMon[nMon-1])->moveHuman(world.Data(), xMax, yMax, key);
                }
            }
            // 모든 몬스터 이동 (Tuman 제외)
            for (int k = 0; k < nMon-2; k++)
                pMon[k]->move(world.Data(), xMax, yMax);
            nMove++;
            checkStarvation();
            print();
            if (isDone() || nMon == 0) break;
            std::this_thread::sleep_for(std::chrono::milliseconds(wait));
        }
        nodelay(stdscr, FALSE);
        timeout(-1);
    }
};
