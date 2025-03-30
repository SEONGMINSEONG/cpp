#ifndef RANKING_H
#define RANKING_H

#include <string>

struct PlayInfo {
    char name[50];      // 고정 크기 문자열로 변경 (이진 파일 저장 용이)
    int nMove;          // 이동 횟수
    double tElapsed;    // 소요 시간
};

void loadRanking(const char* filename);  // 랭킹 파일 로드 (이진 모드)
void storeRanking(const char* filename); // 랭킹 파일 저장 (이진 모드)
void printRanking();                     // 랭킹 출력
int addRanking(int nMove, double tElap, const std::string& name); // 이름 추가

#endif // RANKING_H