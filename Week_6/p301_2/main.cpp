#include <iostream>
#include <limits>
#include "MyDic.h"

// 프로그램 시작점: 인터랙티브 단어장 관리 프로그램
int main() {
    MyDic myDic; // 단어장 객체 생성
    int choice, searchChoice; // 사용자 선택 (메인 메뉴와 검색 서브 메뉴)
    std::string eng, kor, search; // 입력받을 변수
    int id; // 삭제 및 조회용 인덱스
    const std::string defaultFile = "dictionary.txt"; // 기본 파일 이름

    // 프로그램 시작 시 기본 파일에서 단어 읽기
    std::cout << "기본 단어장(" << defaultFile << ")을 로드합니다...\n";
    myDic.load(defaultFile);
    if (myDic.getEng(0).empty()) {
        std::cout << "기본 단어장이 비어 있거나 파일이 없습니다. 새 단어장을 시작합니다.\n";
    } else {
        std::cout << "기본 단어장 로드 완료:\n";
        myDic.print();
    }

    // 인터랙티브 메뉴
    while (true) {
        std::cout << "\n=== 나만의 단어장 ===\n";
        std::cout << "1. 단어 추가\n";
        std::cout << "2. 단어 삭제\n";
        std::cout << "3. 단어장 출력\n";
        std::cout << "4. 단어 검색\n";
        std::cout << "5. 종료\n";
        std::cout << "선택 (1-5): ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: { // 단어 추가
                std::cout << "영어 단어: ";
                std::getline(std::cin, eng);
                std::cout << "한글 설명: ";
                std::getline(std::cin, kor);
                myDic.add(eng, kor);
                myDic.store(defaultFile);
                std::cout << "단어가 추가되고 " << defaultFile << "에 저장되었습니다.\n";
                break;
            }

            case 2: { // 단어 삭제
                myDic.print();
                std::cout << "삭제할 단어 번호: ";
                std::cin >> id;
                myDic.remove(id - 1);
                myDic.store(defaultFile);
                std::cout << "단어가 삭제되고 " << defaultFile << "에 저장되었습니다.\n";
                break;
            }

            case 3: { // 단어장 출력
                std::cout << "단어장 내용:\n";
                myDic.print();
                break;
            }

            case 4: { // 단어 검색 (영어/한글 선택 가능)
                std::cout << "\n=== 단어 검색 ===\n";
                std::cout << "1. 영어 단어로 검색\n";
                std::cout << "2. 한글 설명으로 검색\n";
                std::cout << "선택 (1-2): ";
                std::cin >> searchChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                bool found = false;
                switch (searchChoice) {
                    case 1: { // 영어 단어로 검색
                        std::cout << "검색할 영어 단어: ";
                        std::getline(std::cin, search);
                        for (int i = 0; i < 100; i++) {
                            if (myDic.getEng(i).empty()) break;
                            if (myDic.getEng(i) == search) {
                                std::cout << "찾은 단어: " << myDic.getEng(i) << " - " << myDic.getKor(i) << "\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            std::cout << "단어를 찾을 수 없습니다: " << search << "\n";
                        }
                        break;
                    }

                    case 2: { // 한글 설명으로 검색
                        std::cout << "검색할 한글 설명: ";
                        std::getline(std::cin, search);
                        for (int i = 0; i < 100; i++) {
                            if (myDic.getKor(i).empty()) break;
                            if (myDic.getKor(i) == search) {
                                std::cout << "찾은 단어: " << myDic.getEng(i) << " - " << myDic.getKor(i) << "\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            std::cout << "단어를 찾을 수 없습니다: " << search << "\n";
                        }
                        break;
                    }

                    default: {
                        std::cout << "잘못된 선택입니다. 1-2 사이의 숫자를 입력하세요.\n";
                        break;
                    }
                }
                break;
            }

            case 5: { // 종료
                std::cout << "프로그램을 종료합니다.\n";
                return 0;
            }

            default: {
                std::cout << "잘못된 선택입니다. 1-5 사이의 숫자를 입력하세요.\n";
                break;
            }
        }
    }

    return 0;
}