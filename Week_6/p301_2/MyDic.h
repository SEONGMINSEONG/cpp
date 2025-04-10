#ifndef MYDIC_H
#define MYDIC_H

#include <string>
#include <fstream>
#include <iostream>

const int MAXWORDS = 100;

struct WordPair {
    std::string eng;
    std::string kor;
};

class MyDic {
    WordPair words[MAXWORDS];
    int nkwords;

public:
    inline MyDic() : nkwords(0) {}

    inline void add(const std::string& eng, const std::string& kor) {
        if (nkwords < MAXWORDS) {
            words[nkwords].eng = eng;
            words[nkwords].kor = kor;
            nkwords++;
        } else {
            std::cout << "단어장이 가득 찼습니다!\n";
        }
    }

    inline void remove(int id) {
        if (id < 0 || id >= nkwords) {
            std::cout << "유효하지 않은 인덱스입니다.\n";
            return;
        }
        for (int i = id; i < nkwords - 1; i++) {
            words[i] = words[i + 1];
        }
        nkwords--;
    }

    inline void load(std::string filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "파일을 열 수 없습니다: " << filename << "\n";
            return;
        }
        nkwords = 0;
        std::string line;
        while (std::getline(file, line) && nkwords < MAXWORDS) {
            size_t pos = line.find(' ');
            if (pos == std::string::npos) {
                std::cout << "잘못된 형식의 줄: " << line << "\n";
                continue;
            }
            std::string eng = line.substr(0, pos);
            std::string kor = line.substr(pos + 1);
            if (eng.empty() || kor.empty()) {
                std::cout << "빈 단어 또는 설명: " << line << "\n";
                continue;
            }
            words[nkwords].eng = eng;
            words[nkwords].kor = kor;
            nkwords++;
        }
        if (nkwords == MAXWORDS) {
            std::cout << "최대 단어 수(" << MAXWORDS << ")에 도달했습니다. 더 이상 읽을 수 없습니다.\n";
        }
        file.close();
    }

    inline void store(std::string filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "파일을 열 수 없습니다: " << filename << "\n";
            return;
        }
        for (int i = 0; i < nkwords; i++) {
            file << words[i].eng << " " << words[i].kor << "\n";
        }
        file.close();
    }

    inline void print() {
        if (nkwords == 0) {
            std::cout << "단어장이 비어 있습니다.\n";
            return;
        }
        for (int i = 0; i < nkwords; i++) {
            std::cout << i + 1 << ". " << getEng(i) << " - " << getKor(i) << "\n"; // getEng, getKor 사용
        }
    }

    inline std::string getEng(int id) {
        if (id >= 0 && id < nkwords) {
            return words[id].eng;
        }
        return "";
    }

    inline std::string getKor(int id) {
        if (id >= 0 && id < nkwords) {
            return words[id].kor;
        }
        return "";
    }
};

#endif