#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void playRussianRoulette(int n) {
    if (n < 1) {
        std::cout << "잘못된 총알 수입니다. 총알 수는 1 이상이어야 합니다." << std::endl;
        return;
    }

    std::vector<int> chamber(n, 0);
    int bulletPosition = rand() % n;
    chamber[bulletPosition] = 1;

    std::cout << "러시안 룰렛 게임 시작!" << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << "플레이어 " << i + 1 << " 의 차례입니다." << std::endl;

        if (chamber[i % n] == 1) {
            std::cout << "빵! 총알이 발사되었습니다! 플레이어 " << i + 1 << "는 죽었습니다." << std::endl;
            return;
        } else {
            std::cout << "탕! 안전합니다. 다음 차례로 넘어갑니다." << std::endl;
        }
    }

    std::cout << "모든 플레이어가 살아남았습니다!" << std::endl;
}

int main() {
    int n;

    std::cout << "총알의 개수를 입력하세요 (1 이상의 값): ";
    std::cin >> n;

    srand(static_cast<unsigned int>(time(0)));
    playRussianRoulette(n);

    return 0;
}