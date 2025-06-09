#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include "FileException.h"
using namespace std;
#define NUM_MVP 5

struct PlayInfo {
    string name;
    int nItem;
    double itemPerMove;
    PlayInfo(string na = "Anonymous", int ni = 0, double ipm = 0.0)
        : name(na), nItem(ni), itemPerMove(ipm) {}
};

class RankingBoard {
    PlayInfo MVP[NUM_MVP];
    int nMVP = NUM_MVP;
    const string ADMIN_PASSWORD = "1234"; // 관리자 비밀번호

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

    void store(string) { // filename 인자는 사용하지 않음
        // 입력 모드 설정
        echo();
        nodelay(stdscr, FALSE);
        clear();
        printw("Enter admin password to save ranking: ");
        refresh();

        // 비밀번호 입력 (마스크 처리)
        char password[100] = {0};
        int ch, i = 0;
        while ((ch = getch()) != '\n' && i < 99) {
            if (ch == KEY_BACKSPACE || ch == 127) { // 백스페이스 처리
                if (i > 0) {
                    i--;
                    password[i] = '\0';
                    printw("\b \b");
                    refresh();
                }
                continue;
            }
            password[i++] = ch;
            printw("*");
            refresh();
        }
        password[i] = '\0';

        // 비밀번호 확인
        if (string(password) != ADMIN_PASSWORD) {
            clear();
            printw("Incorrect password. Program terminated.\n");
            refresh();
            getch();
            endwin();
            exit(1); // 프로그램 종료
        }

        // 새로운 파일 이름 입력
        clear();
        printw("Enter file name to save ranking: ");
        refresh();
        char filename[100] = {0};
        getstr(filename);

        // 파일 저장
        ofstream os;
        os.open(filename);
        if (!os)
            throw(FileException(filename, false));
        for (int i = 0; i < nMVP; i++)
            os << MVP[i].nItem << " " << MVP[i].name << " "
               << MVP[i].itemPerMove << "\n";
        os.close();
        clear();
        printw("Ranking saved successfully to %s.\n", filename);
        printw("Press Enter to continue...");
        refresh();
        getch();

        // 원래 입력 모드 복원
        noecho();
        nodelay(stdscr, TRUE);
    }

    void print(string title = "Ranking Board") {
        clear();
        printw("%s\n", title.c_str());
        for (int i = 0; i < nMVP; i++)
            printw("[%d] %s\t%d %.2f\n", i + 1, MVP[i].name.c_str(),
                   MVP[i].nItem, MVP[i].itemPerMove);
        printw("Press Enter to continue...");
        refresh();
        getch();
    }

    int add(int nItem, double ipm) {
        if (nItem <= MVP[nMVP - 1].nItem) return 0;

        int pos = nMVP - 1;
        for (; pos > 0; pos--) {
            if (nItem <= MVP[pos - 1].nItem) break;
            MVP[pos] = MVP[pos - 1];
        }
        MVP[pos].nItem = nItem;
        MVP[pos].itemPerMove = ipm;
        clear();
        printw("\n[%d] Enter name: ", pos + 1);
        refresh();
        echo();
        nodelay(stdscr, FALSE);
        char name[100];
        getstr(name);
        MVP[pos].name = string(name);
        noecho();
        nodelay(stdscr, TRUE);
        return pos + 1;
    }
};