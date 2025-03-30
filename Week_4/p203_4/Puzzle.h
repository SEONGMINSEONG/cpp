#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <chrono>
#include <string>

enum Direction { Left = 'a', Right = 'd', Up = 'w', Down = 's' };  // 방향 정의

class PuzzleGame {
private:
    std::vector<std::vector<int>> map;  // 현재 퍼즐 맵
    std::vector<std::vector<int>> initialMap;  // 최초 섞인 퍼즐 맵
    int dim;  // 퍼즐 크기 (3, 4, 5)
    int emptyX, emptyY;  // 빈칸 위치
    int nMove;           // 이동 횟수
    std::chrono::steady_clock::time_point tStart;  // 시작 시간
    std::vector<int> moveHistory;  // 이동 기록 (방향 저장)
    std::string playerName;  // 플레이어 이름
    bool gameCompleted;  // 게임 완료 여부

public:
    PuzzleGame(int size);  // 생성자
    void init();  // 퍼즐 초기화
    void display();  // 퍼즐 출력
    bool move(int dir);  // 퍼즐 이동
    bool isDone();  // 퍼즐 완성 여부 확인
    void shuffle(int n);  // 퍼즐 섞기
    void replayGame(double elapsedTime);  // 리플레이 기능 (고정된 시간 전달)
    void saveGame(const char* filename);  // 게임 저장 (텍스트 파일로)
    void loadGame(const char* filename);  // 게임 불러오기 (텍스트 파일로)
    int endGame();  // 게임 종료 및 랭킹 반환
    int playFifteenPuzzle(bool isNewGame);  // 게임 실행 (새 게임 여부 추가)
    void setPlayerName(const std::string& name);  // 플레이어 이름 설정
private:
    void displayReplay(const std::vector<std::vector<int>>& replayMap, int moves, double elapsed);  // 리플레이용 출력 함수
};

char getch();  // getch 함수 선언 추가

#endif // PUZZLE_H