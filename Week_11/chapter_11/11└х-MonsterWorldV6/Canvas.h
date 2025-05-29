#pragma once
#include <iostream>
#include <string>
#include "Point.h"			// Point 사용을 위해 추가
#define MAXLINES 100
using namespace std;

class Canvas {
	string line[MAXLINES];
	int xMax, yMax;
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');
	}
	void draw(int x, int y, string val) {
		if (x >= 0 && y >= 0 && x<xMax && y<yMax)
			line[y].replace(x * 2, 2, val);
	}

	// 다음 함수 추가
	void draw(Point& p, string val) { draw(p.x, p.y, val); }

	void clear(string val = ". ") {		
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
	void print(char *title = "<My Canvas>") {
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};