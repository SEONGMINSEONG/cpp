#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

// 전역 변수로 점수 누적
int totalScore = 0;

// 구구단 게임
void playGuguOnce() {
    int a = rand() % 9 + 1;
    int b = rand() % 9 + 1;
    int answer;

    cout << a << " x " << b << " = ? ";
    cin >> answer;

    if (answer == a * b) {
        cout << "정답!\n";
        totalScore += 10;  // 정답일 때 점수 추가
    } else {
        cout << "틀렸습니다. 정답: " << a * b << "\n";
    }
}

// 두 자리 수 곱셈 게임
void playMultiplication() {
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;
    int answer;

    cout << a << " x " << b << " = ? ";
    cin >> answer;

    if (answer == a * b) {
        cout << "정답!\n";
        totalScore += 10;  // 정답일 때 점수 추가
    } else {
        cout << "틀렸습니다. 정답: " << a * b << "\n";
    }
}

// 여러 자리 수 덧셈 게임
void playAddition(int digits) {
    int num1 = rand() % (int)pow(10, digits);
    int num2 = rand() % (int)pow(10, digits);
    int answer;

    cout << num1 << " + " << num2 << " = ? ";
    cin >> answer;

    if (answer == num1 + num2) {
        cout << "정답!\n";
        totalScore += 10;  // 정답일 때 점수 추가
    } else {
        cout << "틀렸습니다. 정답: " << num1 + num2 << "\n";
    }
}

// 게임 시작 함수
void startGame() {
    srand(time(0));

    cout << "스피드 숫자 게임\n";
    cout << "당신의 스피드 숫자 게임을 테스트하세요!!\n\n";

    int choice;
    cout << "어떤 게임을 선택하시겠습니까?\n";
    cout << "1. 구구단 게임\n";
    cout << "2. 두 자리 수 곱셈 게임\n";
    cout << "3. 여러 자리 수 덧셈 게임\n";
    cout << "선택: ";
    cin >> choice;

    const int questionCount = 5;  // 문제 개수 고정 (5문제)

    cout << questionCount << "개의 문제를 풀게 됩니다.\n";
    cout << "크게 심호흡 하시고 준비되면 엔터를 누르세요...";
    cin.ignore();  // 이전 입력 버퍼를 비우고
    cin.get();  // 엔터 키를 기다립니다.

    auto startTime = high_resolution_clock::now();  // 타이머 시작

    switch (choice) {
        case 1:
            for (int i = 0; i < questionCount; ++i) {
                playGuguOnce();
            }
            break;
        case 2:
            for (int i = 0; i < questionCount; ++i) {
                playMultiplication();
            }
            break;
        case 3: {
            int digits;
            cout << "몇 자리 수를 더할까요? ";
            cin >> digits;
            for (int i = 0; i < questionCount; ++i) {
                playAddition(digits);
            }
            break;
        }
        default:
            cout << "잘못된 선택입니다.\n";
            return;
    }

    auto endTime = high_resolution_clock::now();  // 타이머 종료
    auto duration = duration_cast<seconds>(endTime - startTime);

    // 초당 2점씩 차감
    int finalScore = totalScore - (duration.count() * 2);
    if (finalScore < 0) finalScore = 0;  // 점수는 음수가 되지 않도록 처리

    // 최종 점수 출력
    cout << "\n총 걸린 시간: " << duration.count() << "초\n";
    cout << "최종 점수: " << finalScore << "점\n";

    // 게임 종료
    cout << "게임을 종료합니다.\n";
}

int main() {
    startGame();  // 게임 시작
    return 0;
}


