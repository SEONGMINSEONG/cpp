#include <iostream>      // 방법 5 함수 선언 in 헤더 파일 함수 정의, 호출 in 소스 파일
#include <cstdlib>       // <-표준 라이브러리 헤더 파일 4가지
#include <ctime>
#include <vector>
// (함수 정의)
void playRussianRoulette(int n) {         // 총알 개수 n을 사용하여 게임 진행
    if (n < 1) {
        std::cout << "잘못된 총알 수입니다. 총알 수는 1 이상이어야 합니다." << std::endl; 
        return;                           // 총알 수가 1 미만이면 오류 메시지 출력 후 게임 종료
    }

    std::vector<int> chamber(n, 0);       // 슬롯을 만들고 각 슬롯을 0으로 초기화
    int bulletPosition = rand() % n;      // 0부터 n-1까지의 범위로 변환
    chamber[bulletPosition] = 1;          // 랜덤한 위치에 총알(1) 배치

    std::cout << "러시안 룰렛 게임 시작!" << std::endl;         // 게임 시작 메시지를 출력

    for (int i = 0; i < n; ++i) {         // n명 플레이어가 차례대로 게임을 진행     
        std::cout << "플레이어 " << i + 1 << " 의 차례입니다." << std::endl;
                                                            // 현재 플레이어 차례를 출력
        if (chamber[i % n] == 1) {        // 플레이어의 슬롯에 총알이 있는지 확인
            std::cout << "빵! 총알이 발사되었습니다! 플레이어 " << i + 1 << "는 죽었습니다." << std::endl;
            return;          //  게임을 종료                  // 총알이 있으면 죽음 메시지 출력
        } else {
            std::cout << "탕! 안전합니다. 다음 차례로 넘어갑니다." << std::endl;
        }                                                  // 총알이 없으면 안전 메시지 출력
    }

    std::cout << "모든 플레이어가 살아남았습니다!" << std::endl;  // 게임이 끝났다는 메시지를 출력
}

int main() {                // 프로그램의 시작점
    int n;                  // 사용자 입력 값을 저장할 변수

    std::cout << "총알의 개수를 입력하세요 (1 이상의 값): ";    // 입력
    std::cin >> n;          // 사용자가 입력한 값을 n에 저장

    srand(static_cast<unsigned int>(time(0)));           // 현재 시간을 시드로 난수 생성기 초기화
    playRussianRoulette(n); // 러시안 룰렛 게임 실행 (함수 호출)

    return 0;               // 정상 종료
}