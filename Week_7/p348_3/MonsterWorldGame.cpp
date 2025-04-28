#include "MonsterWorld.h"
#include <time.h>
#include <cstdlib>

int main() {
    srand((unsigned int)time(NULL));
    int w = 16, h = 8;

    MonsterWorld game(w, h);
    Monster m1("몬스터", "★", rand() % w, rand() % h);
    Monster m2("도깨비", "■", rand() % w, rand() % h);
    Monster m3("별그대", "☆", rand() % w, rand() % h);
    Monster m4("고스트", "●", rand() % w, rand() % h);

    game.add(m1);
    game.add(m2);
    game.add(m3);
    game.add(m4);

    game.play(500, 10);
    printf("------게임 종료-------------------\n");

    return 0;
}