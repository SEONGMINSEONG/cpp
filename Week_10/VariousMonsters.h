#pragma once

#include "Monster.h"
#include <ncurses.h>

class Zombie : public Monster {
public:
    Zombie(string n = "Zombie", string i = "*", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Zombie() override { printw(" Zombie"); }
};

class Vampire : public Monster {
public:
    Vampire(string n = "Vampire", string i = "#", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Vampire() override { printw(" Vampire"); }

    void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 4;
        if (dir == 0) x--;
        else if (dir == 1) x++;
        else if (dir == 2) y--;
        else y++;
        clip(maxx, maxy);
        eat(map);
    }
};

class KGhost : public Monster {
public:
    KGhost(string n = "Ghost", string i = "&", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~KGhost() override { printw(" KGhost"); }

    void move(int** map, int maxx, int maxy) override {
        x = rand() % maxx;
        y = rand() % maxy;
        clip(maxx, maxy);
        eat(map);
    }
};

class Jiangshi : public Monster {
protected:
    bool bHori;
    static int moveCount;

public:
    Jiangshi(string n = "Jiangshi", string i = "%", int x = 0, int y = 0, bool bH = true)
        : Monster(n, i, x, y), bHori(bH) {}
    ~Jiangshi() override { printw(" Jiangshi"); }

    virtual void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 2;
        int jump = rand() % 2 + 1;
        if (bHori) x += ((dir == 0) ? -jump : jump);
        else y += ((dir == 0) ? -jump : jump);
        clip(maxx, maxy);
        eat(map);
        moveCount++;
    }
};

int Jiangshi::moveCount = 0;

class Smombi : public Monster {
public:
    Smombi(string n = "Smombi", string i = "!", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Smombi() override { printw(" Smombi"); }

    void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 4;
        if (dir == 0) { x++; y++; }
        else if (dir == 1) { x++; y--; }
        else if (dir == 2) { x--; y++; }
        else { x--; y--; }
        clip(maxx, maxy);
        eat(map);
    }
};

class Siangshi : public Jiangshi {
private:
    bool canMoveFreely;
    static const int MOVE_THRESHOLD = 150;

public:
    Siangshi(string n = "Siangshi", string i = "@", int x = 0, int y = 0, bool bH = true)
        : Jiangshi(n, i, x, y, bH), canMoveFreely(false) {}
    ~Siangshi() override { printw(" Siangshi"); }

    void move(int** map, int maxx, int maxy) override {
        if (!canMoveFreely && moveCount >= MOVE_THRESHOLD) {
            canMoveFreely = true;
            printw("Siangshi can now move freely at Jiangshi move count %d\n", moveCount);
        }
        if (canMoveFreely) {
            int dir = rand() % 2;
            int jump = rand() % 2 + 1;
            if (bHori) x += ((dir == 0) ? -jump : jump);
            else y += ((dir == 0) ? -jump : jump);
            clip(maxx, maxy);
            eat(map);
            bHori = !bHori; 
        }
    }
};

class Seong : public Jiangshi {
public:
    Seong(string n = "Seong", string i = "^", int x = 0, int y = 0, bool bH = true)
        : Jiangshi(n, i, x, y, bH) {}
    ~Seong() override { printw(" Seong"); }

    void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 2;
        int jump = 3;
        if (bHori) x += (dir == 0) ? -jump : jump;
        else y += (dir == 0) ? -jump : jump;
        clip(maxx, maxy);
        eat(map);
    }
};

class Human : public Monster {
public:
    Human(string n = "Human", string i = "H", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Human() override { printw(" Human"); }

    void moveHuman(int** map, int maxx, int maxy, int key) override {}
};

class Tuman : public Human {
public:
    Tuman(string n = "Tuman", string i = "H", int x = 0, int y = 0)
        : Human(n, i, x, y) {}
    ~Tuman() override { printw(" Tuman"); }

    void moveHuman(int** map, int maxx, int maxy, int key) override {
        if (key == 'w' || key == KEY_UP) y--; // Up
        else if (key == 's' || key == KEY_DOWN) y++; // Down
        else if (key == 'a' || key == KEY_LEFT) x--; // Left
        else if (key == 'd' || key == KEY_RIGHT) x++; // Right
        clip(maxx, maxy);
        eat(map);
    }
};