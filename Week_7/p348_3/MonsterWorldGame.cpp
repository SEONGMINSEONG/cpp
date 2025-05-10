#include "MonsterWorld.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    // 1. 캔버스 초기 환경 설정
    srand((unsigned int)time(NULL));    // 역할: 무작위 움직임을 위해 랜덤 설정
    int w = 16, h = 8;                  // 역할: 16x8 크기의 게임판 준비
    MonsterWorld game(w, h);            // 역할: 16x8 게임판을 만들고 초기화

    // 2. 몬스터 추가
    Monster m("몬스터", "*", rand() % w, rand() % h);  // 역할: "몬스터" 이름과 "*" 아이콘을 가진 몬스터 생성
    game.add(m);                                      // 역할: 몬스터를 게임에 추가
    Monster m1("도깨비", "#", rand() % w, rand() % h); // 역할: "도깨비" 이름과 "#" 아이콘을 가진 몬스터 생성
    game.add(m1);                                     // 역할: 도깨비 몬스터를 게임에 추가
    Monster m2("별그대", "&", rand() % w, rand() % h); // 역할: "별그대" 이름과 "&" 아이콘을 가진 몬스터 생성
    game.add(m2);                                     // 역할: 별그대 몬스터를 게임에 추가
    Monster m3("고스트", "%", rand() % w, rand() % h); // 역할: "고스트" 이름과 "%" 아이콘을 가진 몬스터 생성
    game.add(m3);                                     // 역할: 고스트 몬스터를 게임에 추가

    // 3. 게임 시작 및 종료
    game.play(500, 50);                              // 역할: 게임을 최대 500번 이동, 50ms 대기로 실행
    printf("------게임 종료-------------------\n");     // 역할: 게임 종료 메시지 출력
    return 0;                                         // 역할: 프로그램 종료
}