#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include "RankingBoard.h"
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); // 한글 출력을 위한 로케일 설정
    srand(static_cast<unsigned int>(time(nullptr)));
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();

    int w = 16, h = 8;
    MonsterWorld game(w, h);

    game.add(new Zombie("ZombiePrincess", "*", rand() % w, rand() % h));
    game.add(new Vampire("VampireKing", "#", rand() % w, rand() % h));
    game.add(new KGhost("LittleGhost", "&", rand() % w, rand() % h));
    game.add(new Jiangshi("JiangshiBoy", "%", rand() % w, rand() % h, true));
    game.add(new Jiangshi("JiangshiGirl", "$", rand() % w, rand() % h, false));
    game.add(new Smombi("Smombi", "!", rand() % w, rand() % h));
    Monster* leftPlayer = new Tuman("LeftPlayer", "L", rand() % w, rand() % h);
    Monster* rightPlayer = new Tuman("RightPlayer", "R", rand() % w, rand() % h);
    game.add(leftPlayer);
    game.add(rightPlayer);

    game.play(500, 100);
    clear();
    printw("------Game Over-------------------\n");
    refresh();
    getch();

    // 랭킹 저장
    RankingBoard rb;
    try {
        rb.load("ranking.txt");
    } catch (FileException& e) {
        clear();
        printw("Failed to load ranking file: %s\n", e.filename.c_str());
        printw("Press Enter to continue...");
        refresh();
        getch();
    }

    // LeftPlayer와 RightPlayer의 점수 추가
    int totalMoves = 500; // game.play의 maxwalk
    int leftItems = leftPlayer->getItems();
    int rightItems = rightPlayer->getItems();
    if (leftItems > 0)
        rb.add(leftItems, (double)leftItems / totalMoves);
    if (rightItems > 0)
        rb.add(rightItems, (double)rightItems / totalMoves);

    try {
        rb.store("ranking.txt");
    } catch (FileException& e) {
        clear();
        printw("Failed to save ranking file: %s\n", e.filename.c_str());
        printw("Press Enter to continue...");
        refresh();
        getch();
    }
    rb.print();

    getch();
    endwin();
    delete leftPlayer;
    delete rightPlayer;
    return 0;
};