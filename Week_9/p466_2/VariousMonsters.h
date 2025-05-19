#pragma once

#include "Monster.h"

class Zombie : public Monster {
public:
    Zombie(string n = "Zombie", string i = "*", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Zombie() override { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
    Vampire(string n = "Vampire", string i = "#", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Vampire() override { cout << " Vampire"; }

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
    ~KGhost() override { cout << " KGhost"; }

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

public:
    Jiangshi(string n = "Jiangshi", string i = "%", int x = 0, int y = 0, bool bH = true)
        : Monster(n, i, x, y), bHori(bH) {}
    ~Jiangshi() override { cout << " Jiangshi"; }

    virtual void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 2;
        int jump = rand() % 2 + 1;
        if (bHori) x += ((dir == 0) ? -jump : jump);
        else y += ((dir == 0) ? -jump : jump);
        clip(maxx, maxy);
        eat(map);
    }
};

class Smombi : public Monster {
public:
    Smombi(string n = "Smombi", string i = "!", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Smombi() override { cout << " Smombi"; }

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
    int moveCount;
    static const int CHANGE_INTERVAL = 5;

public:
    Siangshi(string n = "Siangshi", string i = "@", int x = 0, int y = 0, bool bH = true)
        : Jiangshi(n, i, x, y, bH), moveCount(0) {}
    ~Siangshi() override { cout << " Siangshi"; }

    void move(int** map, int maxx, int maxy) override {
        moveCount++;
        if (moveCount >= CHANGE_INTERVAL) {
            bHori = !bHori;
            moveCount = 0;
        }
        Jiangshi::move(map, maxx, maxy);
    }
};

class Seong : public KGhost {
public:
    Seong(string n = "Seong", string i = "^", int x = 0, int y = 0)
        : KGhost(n, i, x, y) {}
    ~Seong() override { cout << " Seong"; }

    void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 4;
        if (dir == 0) x += 2; // 오른쪽 2칸
        else if (dir == 1) x -= 2; // 왼쪽 2칸
        else if (dir == 2) y += 2; // 아래 2칸
        else y -= 2; // 위 2칸
        clip(maxx, maxy);
        eat(map);
    }
};