#pragma once
#include <iostream>
#include <fstream>
#include "FileException.h"
using namespace std;
#define NUM_MVP	5

struct PlayInfo {		// 게임 정보 클래스
	string name;		// 게이머의 이름
	int nItem;		// 획득한 아이템의 수
	double itemPerMove;	// 이동 거리당 아이템 수
	PlayInfo(string na = "신인류", int ni = 0, double ipm = 0.0)
		: name(na), nItem(ni), itemPerMove(ipm) {}
};

class RankingBoard {		// 랭킹 관리 클래스
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;
public:
	void load(string filename) {
		ifstream is;
		is.open(filename);
		if (!is)
			throw(FileException(filename, true));
		for (int i = 0; i < nMVP; i++)
			is >> MVP[i].nItem >> MVP[i].name >> MVP[i].itemPerMove;
		is.close();
	}
	void store(string filename) {
		ofstream os;
		os.open(filename);
		if (!os)
			throw(FileException(filename, false));
		for (int i = 0; i < nMVP; i++)
			os << MVP[i].nItem << " " << MVP[i].name << " "
			<< MVP[i].itemPerMove << "\n";
		os.close();
	}
	void print(string title = "게임 랭킹") {
		cout << endl << title << endl;
		for (int i = 0; i<nMVP; i++)
			cout << "[" << i + 1 << "위] " << MVP[i].name << "\t"
			<< MVP[i].nItem << " " << MVP[i].itemPerMove << "\n";
		cout << "엔터를 입력하세요.";
		getchar();
		cout << endl;
	}
	int add(int nItem, double ipm) {
		if (nItem <= MVP[nMVP - 1].nItem) return 0;

		int pos = nMVP - 1;
		for (; pos>0; pos--) {
			if (nItem <= MVP[pos - 1].nItem) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nItem = nItem;
		MVP[pos].itemPerMove = ipm;
		cout << "\n[" << pos + 1 << "위] 이름을 입력하세요: ";
		cin >> MVP[pos].name;
		return pos + 1;
	}
};