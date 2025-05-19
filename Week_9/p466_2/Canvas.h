#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

class Canvas {
    string line[MAXLINES];
    int xMax, yMax;

public:
    Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {
        for (int y = 0; y < yMax; y++)
            line[y] = string(xMax, '.');
    }

    void draw(int x, int y, string val) {
        if (x >= 0 && y >= 0 && x < xMax && y < yMax && !val.empty()) {
            line[y][x] = val[0];
        }
    }

    void clear(string val = ".") {
        for (int y = 0; y < yMax; y++)
            line[y] = string(xMax, val[0]);
    }

    void print(const char *title = "<My Canvas>") {
        cout << title << endl;
        for (int y = 0; y < yMax; y++)
            cout << line[y] << endl;
        cout << endl;
    }
};