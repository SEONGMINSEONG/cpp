#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int w = 16, h = 8;
    MonsterWorld game(w, h);

    game.add(new Zombie("ZombiePrincess", "*", rand() % w, rand() % h));
    game.add(new Vampire("VampireKing", "#", rand() % w, rand() % h));
    game.add(new KGhost("LittleGhost", "&", rand() % w, rand() % h));
    game.add(new Jiangshi("JiangshiBoy", "%", rand() % w, rand() % h, true));
    game.add(new Jiangshi("JiangshiGirl", "$", rand() % w, rand() % h, false));
    game.add(new Smombi("Smombi", "!", rand() % w, rand() % h));
    game.add(new Siangshi("SuperSiangshi", "@", rand() % w, rand() % h, true));
    game.add(new Seong("SeongMonster", "^", rand() % w, rand() % h));

    game.play(500, 100);
    printf("------Game Over-------------------\n");
    return 0;
}