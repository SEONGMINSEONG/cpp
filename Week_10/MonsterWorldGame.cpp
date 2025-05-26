#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <ctime>
#include <cstdlib>
#include <ncurses.h>

int main() {
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
    game.add(new Tuman("LeftPlayer", "L", rand() % w, rand() % h));
    game.add(new Tuman("RightPlayer", "R", rand() % w, rand() % h));

    game.play(500, 100);
    printw("------Game Over-------------------\n");
    refresh();
    getch();
    endwin();
    return 0;
}