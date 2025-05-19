#pragma once
#include "Canvas.h"
#include "VariousMonsters.h"
#include "Matrix.h"
#include <chrono>
#include <thread>

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

    void print() {
        canvas.clear();
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0)
                    canvas.draw(x, y, "O");
        for (int i = 0; i < nMon; i++)
            pMon[i]->draw(canvas);
        cout << "\033[2J\033[H"; 
        canvas.print("[ Monster World (All Monsters Moving) ]");
        cout << "Total Moves = " << nMove << endl;
        cout << "Remaining Items = " << countItems() << endl;
        for (int i = 0; i < nMon; i++)
            pMon[i]->print();
        cout << flush;
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
        cout << "Press Enter...";
        cin.get();
        print();
        for (int i = 0; i < maxwalk; i++) {
            for (int k = 0; k < nMon; k++)
                pMon[k]->move(world.Data(), xMax, yMax);
            nMove++;
            print();
            if (isDone()) break;
            this_thread::sleep_for(chrono::milliseconds(wait));
        }
    }
};