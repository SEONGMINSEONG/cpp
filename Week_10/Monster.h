#pragma once
#include "Canvas.h"
#include <ncurses.h>
#define DIM 40

class Monster {
protected:
    string name, icon;
    int x, y, nItem, nEnergy;
    static int count;

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int** map) {
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            nEnergy += 8;
        } else {
            nEnergy -= 1;
            if (nEnergy < 0) nEnergy = 0;
        }
    }

public:
    Monster(string n = "Monster", string i = "*", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {
        count++;
    }
    virtual ~Monster() { 
        printw("\t%s%s Destroyed~~~\n", name.c_str(), icon.c_str()); 
        count--;
    }

    virtual void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
    virtual void move(int** map, int maxx, int maxy) {
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

    virtual void moveHuman(int** map, int maxx, int maxy, int key) {}

    void print() { printw("\t%s%s:%d (Energy: %d)\n", name.c_str(), icon.c_str(), nItem, nEnergy); }
    int getEnergy() { return nEnergy; }
    string getName() { return name; }
    string getIcon() { return icon; }
    static void printCount() { printw("Total Monsters = %d\n", count); }
};

int Monster::count = 0;