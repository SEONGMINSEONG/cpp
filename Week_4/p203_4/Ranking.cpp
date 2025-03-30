#include "Ranking.h"
#include <fstream>
#include <iostream>  // std::cerr을 사용하기 위해 추가
#include <cstring>
#include <algorithm>

static PlayInfo MVP[10];  // 상위 10개 기록 저장
static const int nMVP = 10;

bool compareRecords(const PlayInfo& a, const PlayInfo& b) {
    return a.nMove < b.nMove;  // 이동 횟수 기준으로 정렬
}

void loadRanking(const char* filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        // 파일이 없으면 기본값으로 초기화
        PlayInfo noname;
        std::strncpy(noname.name, "C++ Master", sizeof(noname.name) - 1);
        noname.name[sizeof(noname.name) - 1] = '\0';
        noname.nMove = 1000;
        noname.tElapsed = 1000.0;
        for (int i = 0; i < nMVP; i++) {
            MVP[i] = noname;
        }
    } else {
        // 이진 파일에서 읽기
        inFile.read(reinterpret_cast<char*>(MVP), sizeof(PlayInfo) * nMVP);
        inFile.close();
    }
}

void storeRanking(const char* filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "랭킹 저장에 실패했습니다!" << std::endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(MVP), sizeof(PlayInfo) * nMVP);
    outFile.close();
}

void printRanking() {
    printf("\n===== 랭킹 =====\n");
    for (int i = 0; i < nMVP; i++) {
        printf("  [%2d등]  %4d  %-16s %5.1f초\n", i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
    }
}

int addRanking(int nMove, double tElap, const std::string& name) {
    PlayInfo newRecord;
    std::strncpy(newRecord.name, name.c_str(), sizeof(newRecord.name) - 1);
    newRecord.name[sizeof(newRecord.name) - 1] = '\0';  // 안전하게 null 종료
    newRecord.nMove = nMove;
    newRecord.tElapsed = tElap;

    for (int i = 0; i < nMVP; i++) {
        if (nMove < MVP[i].nMove) {
            for (int j = nMVP - 1; j > i; j--) {
                MVP[j] = MVP[j - 1];
            }
            MVP[i] = newRecord;
            return i + 1;
        }
    }
    return 0;
}