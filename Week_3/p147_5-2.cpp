#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "p147_5-2.h"

void playRussianRoulette(int n, int bullets) {
    if (n < 1 || bullets < 1) {
        std::cout << "잘못된 입력입니다. 총알 수와 플레이어 수는 1 이상이어야 합니다." << std::endl;
        return;
    }

    std::vector<int> chamber(n, 0);
    int bulletCount = bullets;

    for (int i = 0; i < bulletCount; ++i) {
        int bulletPosition = rand() % n;
        while (chamber[bulletPosition] == 1) {
            bulletPosition = rand() % n;
        }
        chamber[bulletPosition] = 1;
    }

    std::cout << "러시안 룰렛 게임 시작!" << std::endl;

    int player = 1;
    int bulletsFired = 0;

    while (bulletsFired < bulletCount) {
        std::cout << "플레이어 " << player << " 의 차례입니다." << std::endl;

        if (chamber[(player - 1) % n] == 1) {
            std::cout << "빵! 총알이 발사되었습니다! 플레이어 " << player << "는 죽었습니다." << std::endl;
            bulletsFired++;
        } else {
            std::cout << "탕! 안전합니다. 다음 차례로 넘어갑니다." << std::endl;
        }

        player++;
        if (player > n) {
            player = 1;
        }
    }

    std::cout << "모든 총알이 발사되었습니다! 게임 종료!" << std::endl;
}

int main() {
    int n, bullets;

    std::cout << "플레이어 수를 입력하세요 (1 이상의 값): ";
    std::cin >> n;
    std::cout << "총알 수를 입력하세요 (1 이상의 값): ";
    std::cin >> bullets;

    srand(static_cast<unsigned int>(time(0)));
    playRussianRoulette(n, bullets);

    return 0;
}