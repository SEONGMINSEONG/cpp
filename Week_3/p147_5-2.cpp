#include <iostream>             // 방법 5 함수 선언 in 헤더 파일 함수 정의, 호출 in 소스 파일
#include <cstdlib>              // <-표준 라이브러리 헤더 파일 4가지   
#include <ctime>
#include <vector>
#include "p147_5-2.h"
// (함수 정의)
void playRussianRoulette(int n, int bullets) {          // 플레이어 수(n)와 총알 수(bullets)를 받아 게임을 진행
    if (n < 1 || bullets < 1) {                         //플레이어 수와 총알 수는 1 이상이어야 함
        std::cout << "잘못된 입력입니다. 총알 수와 플레이어 수는 1 이상이어야 합니다." << std::endl;
        return;                                         // 잘못된 입력이면 오류 메시지 출력 후 게임 종료
    }

    std::vector<int> chamber(n, 0);                     // n개의 빈 슬롯 생성 (모두 0으로 초기화)
    int bulletCount = bullets;                          // 총알 개수 저장
 
    for (int i = 0; i < bulletCount; ++i) {             // 총알 개수만큼 반복
        int bulletPosition = rand() % n;                // 랜덤한 위치 선택
        while (chamber[bulletPosition] == 1) {          // 이미 총알이 있으면 다시 선택
            bulletPosition = rand() % n;
        }
        chamber[bulletPosition] = 1;                    // 총알 배치
    }

    std::cout << "러시안 룰렛 게임 시작!" << std::endl;     // 게임 시작 메시지를 출력

    int player = 1;                                 // 플레이어 번호를 1로 시작
    int bulletsFired = 0;                           // 발사된 총알 수

    while (bulletsFired < bulletCount) {            // 총알이 모두 발사될 때까지 반복
        std::cout << "플레이어 " << player << " 의 차례입니다." << std::endl;

        if (chamber[(player - 1) % n] == 1) {       // 현재 플레이어 차례에 총알이 있으면
            std::cout << "빵! 총알이 발사되었습니다! 플레이어 " << player << "는 죽었습니다." << std::endl;
            bulletsFired++;                         // 총알이 발사되면 총알 수 증가
        } else {
            std::cout << "탕! 안전합니다. 다음 차례로 넘어갑니다." << std::endl;
        }

        player++;           // 다음 플레이어로 넘어감
        
    }

    std::cout << "모든 총알이 발사되었습니다! 게임 종료!" << std::endl;     // 게임 종료 메시지
}

int main() {                    // 프로그램의 시작점
    int n, bullets;             // 사용자 입력 값을 저장할 변수 

    std::cout << "플레이어 수를 입력하세요 (1 이상의 값): ";    // 입력
    std::cin >> n;                                       // 사용자가 입력한 값을 n에 저장
    std::cout << "총알 수를 입력하세요 (1 이상의 값): ";       // 입력
    std::cin >> bullets;                                 // 사용자가 입력한 값을 bullets에 저장

    srand(static_cast<unsigned int>(time(0)));          // 현재 시간을 시드로 난수 생성기 초기화
    playRussianRoulette(n, bullets);                    // 러시안 룰렛 게임 실행 (함수 호출)

    return 0;                   // 정상 종료
}