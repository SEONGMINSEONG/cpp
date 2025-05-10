#pragma once
#include <iostream>
#include <string>

#define MAXLINES 100

// 게임 화면 출력을 위한 캔버스 관리
class Canvas {
    std::string line[MAXLINES]; // 화면 저장용 문자열
    int xMax, yMax;            // 캔버스 크기
public:
    Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) { // 생성자 - 역할: 캔버스를 지정된 크기(nx x ny)로 초기화
        for (int y = 0; y < yMax; y++)
            line[y] = std::string(xMax * 2, ' ');
    }
    
    void draw(int x, int y, std::string val) { // 역할: 캔버스의 (x, y) 위치에 문자열을 그림
        if (x >= 0 && y >= 0 && x < xMax && y < yMax) {
            // val 길이가 2인지 확인
            if (val.size() != 2) {
                val = val.size() > 2 ? val.substr(0, 2) : val + " ";
            }
            size_t pos = x * 2;
            if (pos + 2 <= line[y].size()) {
                line[y].replace(pos, 2, val);
            }
        }
    }

    void clear(std::string val = ". ") { // 역할: 캔버스 전체를 지정된 문자열로 초기화
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                draw(x, y, val);
    }

    void print(const char *title = "<My Canvas>") { // 역할: 캔버스 상태를 콘솔에 출력
        system("clear"); // Linux 환경
        std::cout << title << std::endl;
        for (int y = 0; y < yMax; y++)
            std::cout << line[y] << std::endl;
        std::cout << std::endl;
    }
};