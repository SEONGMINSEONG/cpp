#include "Puzzle.h"
#include "Ranking.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <sstream>

PuzzleGame::PuzzleGame(int size) {
    dim = size;
    playerName = "Unknown";
    nMove = 0;
    gameCompleted = false;
    tStart = std::chrono::steady_clock::now();
    map.resize(dim, std::vector<int>(dim));
    initialMap.resize(dim, std::vector<int>(dim));
    init();
}

void PuzzleGame::init() {
    for (int i = 0; i < dim * dim - 1; i++)
        map[i / dim][i % dim] = i + 1;
    map[dim - 1][dim - 1] = 0;
    emptyX = dim - 1;
    emptyY = dim - 1;
    moveHistory.clear();
}

void PuzzleGame::display() {
    system("clear");
    printf("\tFifteen Puzzle\n\tPlayer: %s\n\t--------------\n\t", playerName.c_str());
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            if (map[r][c] > 0)
                printf("%3d", map[r][c]);
            else
                printf("   ");
        }
        printf("\n\t");
    }
    printf("--------------\n\t");
    
    auto tEnd = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = tEnd - tStart;
    printf("\n\t이동 횟수: %6d\n\t소요 시간: %6.1f초\n\n", nMove, elapsed.count());
}

void PuzzleGame::displayReplay(const std::vector<std::vector<int>>& replayMap, int moves, double elapsed) {
    system("clear");
    printf("\tFifteen Puzzle - Replay\n\tPlayer: %s\n\t--------------\n\t", playerName.c_str());
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            if (replayMap[r][c] > 0)
                printf("%3d", replayMap[r][c]);
            else
                printf("   ");
        }
        printf("\n\t");
    }
    printf("--------------\n\t");
    printf("\n\t이동 횟수: %6d\n\t소요 시간: %6.1f초\n\n", moves, elapsed);
}

bool PuzzleGame::move(int dir) {
    int newX = emptyX, newY = emptyY;
    switch (dir) {
        case Right: newX--; break;
        case Left: newX++; break;
        case Up: newY++; break;
        case Down: newY--; break;
        default: return false;
    }

    if (newX >= 0 && newX < dim && newY >= 0 && newY < dim) {
        std::swap(map[emptyY][emptyX], map[newY][newX]);
        emptyX = newX;
        emptyY = newY;
        nMove++;
        moveHistory.push_back(dir);
        return true;
    }
    return false;
}

bool PuzzleGame::isDone() {
    int value = 1;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i == dim - 1 && j == dim - 1) {
                if (map[i][j] != 0) return false;
            } else if (map[i][j] != value++) {
                return false;
            }
        }
    }
    return true;
}

void PuzzleGame::shuffle(int n) {
    std::vector<int> numbers;
    for (int i = 1; i < dim * dim; i++) {
        numbers.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);

    int idx = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i == dim - 1 && j == dim - 1) {
                map[i][j] = 0;
            } else {
                map[i][j] = numbers[idx++];
            }
        }
    }
    emptyX = dim - 1;
    emptyY = dim - 1;

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            initialMap[i][j] = map[i][j];
        }
    }
}

void PuzzleGame::replayGame(double elapsedTime) {
    printf("\n[리플레이 시작]\n");
    std::vector<std::vector<int>> replayMap = initialMap;
    int replayEmptyX = dim - 1, replayEmptyY = dim - 1;
    int replayMoves = 0;

    displayReplay(replayMap, replayMoves, elapsedTime);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    for (int dir : moveHistory) {
        int newX = replayEmptyX, newY = replayEmptyY;
        switch (dir) {
            case Right: newX--; break;
            case Left: newX++; break;
            case Up: newY++; break;
            case Down: newY--; break;
        }
        if (newX >= 0 && newX < dim && newY >= 0 && newY < dim) {
            std::swap(replayMap[replayEmptyY][replayEmptyX], replayMap[newY][newX]);
            replayEmptyX = newX;
            replayEmptyY = newY;
            replayMoves++;
            displayReplay(replayMap, replayMoves, elapsedTime);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    printf("\n[리플레이 끝]\n");
}

void PuzzleGame::saveGame(const char* filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "게임 저장에 실패했습니다!" << std::endl;
        return;
    }

    outFile << dim << "\n";
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            outFile << map[i][j] << " ";
        }
        outFile << "\n";
    }
    outFile << emptyX << " " << emptyY << "\n";
    outFile << nMove << "\n";

    outFile << moveHistory.size() << "\n";
    for (int dir : moveHistory) {
        outFile << dir << " ";
    }
    outFile << "\n";

    auto tEnd = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = tEnd - tStart;
    outFile << elapsed.count() << "\n";

    outFile << playerName << "\n";

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            outFile << initialMap[i][j] << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    printf("게임이 저장되었습니다.\n");
}

void PuzzleGame::loadGame(const char* filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "저장된 게임을 불러올 수 없습니다!" << std::endl;
        return;
    }

    inFile >> dim;
    map.resize(dim, std::vector<int>(dim));
    initialMap.resize(dim, std::vector<int>(dim));
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            inFile >> map[i][j];
        }
    }
    inFile >> emptyX >> emptyY;
    inFile >> nMove;

    size_t historySize;
    inFile >> historySize;
    moveHistory.resize(historySize);
    for (size_t i = 0; i < historySize; i++) {
        inFile >> moveHistory[i];
    }

    double timeElapsed;
    inFile >> timeElapsed;
    auto tNow = std::chrono::steady_clock::now();
    tStart = tNow - std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<double>(timeElapsed));

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(inFile, playerName);

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            inFile >> initialMap[i][j];
        }
    }

    inFile.close();
    if (inFile.fail() || playerName.empty()) {
        std::cerr << "게임 불러오기에 실패했습니다! 데이터 형식이 잘못되었을 수 있습니다." << std::endl;
        playerName = "Unknown";
        init();
        return;
    }

    printf("게임이 불러와졌습니다.\n");
}

int PuzzleGame::endGame() {
    auto tEnd = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = tEnd - tStart;
    gameCompleted = true;

    printf("축하합니다! 퍼즐을 완성했습니다.\n");
    printf("리플레이를 보겠습니까? (y/n): ");
    char replayChoice = getch();
    printf("\n");

    if (replayChoice == 'y' || replayChoice == 'Y') {
        replayGame(elapsed.count());
    }

    std::string name;
    printf("이름을 입력하세요: ");
    std::getline(std::cin, name);
    setPlayerName(name);

    return addRanking(nMove, elapsed.count(), playerName);
}

void PuzzleGame::setPlayerName(const std::string& name) {
    playerName = name;
}

int PuzzleGame::playFifteenPuzzle(bool isNewGame) {
    if (isNewGame) {
        display();
        printRanking();
        printf("\n게임을 시작하려면 Enter를 누르세요...");
        getchar();

        shuffle(100);
        printf("\n게임을 시작합니다...");
        getchar();

        nMove = 0;
        tStart = std::chrono::steady_clock::now();
    }

    while (!isDone()) {
        display();
        char dir = getch();
        if (dir == 'q') {
            saveGame("saved_game.txt");
            return 0;
        } else {
            move(dir);
        }
    }
    if (isDone()) {
        display();
        return endGame();
    }
    return 0;
}

char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = std::cin.get();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    loadRanking("ranking.bin");  // 이진 파일로 변경

    int choice;
    printf("1. 새 게임 시작\n2. 저장된 게임 불러오기\n3. 종료\n");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        int size;
        printf("퍼즐 크기를 선택하세요 (3: 3x3, 4: 4x4, 5: 5x5): ");
        scanf("%d", &size);
        getchar();
        if (size != 3 && size != 4 && size != 5) {
            printf("잘못된 크기입니다. 기본 크기 4x4로 진행합니다.\n");
            size = 4;
        }
        PuzzleGame game(size);
        int rank = game.playFifteenPuzzle(true);
        if (rank > 0) {
            printRanking();
            storeRanking("ranking.bin");  // 이진 파일로 저장
        }
    } else if (choice == 2) {
        PuzzleGame game(4);
        game.loadGame("saved_game.txt");
        int rank = game.playFifteenPuzzle(false);
        if (rank > 0) {
            printRanking();
            storeRanking("ranking.bin");  // 이진 파일로 저장
        }
    }

    storeRanking("ranking.bin");  // 이진 파일로 저장
    return 0;
}