#include <iostream>		// cout 사용
#include <fstream>		// 파일 입력을 위해 사용
#include <string>		// string 클래스 사용
#include <conio.h>		// getch() 사용
using namespace std;		// std 이름 공간 사용

class Hangman {
	string	progress[64];	// 행맨 진행 상태 출력 그림
	string	problem;		// 문제 단어
	string	answer;		// 현재 진행 중인 단어
	string	guessed;		// 전체 알파벳의 현재까지 예측 상황
	int	nTries;		// 현재까지 틀린 횟수
	const int maxTries = 7;	// 최대 허용 시도 횟수 제한

	void load(char* progName = "HangmanProgress.txt") {
		ifstream fs(progName);
		if (fs) {
			getline(fs, progress[0]);	// 첫 번째 행은 주석
			for (int i = 0; i < 64; i++)
				getline(fs, progress[i]);
		}
	}
	void print() {
		system("cls");
		cout << "     <Hangman Game>\n";
		for (int i = 0; i < 8; i++)
			cout << '\t' << progress[nTries * 8 + i] << endl;
		cout << "\n\t" << answer;
		cout << "\n\n " << guessed;
	}
	int countMatched(char ch) {
		int nMatched = 0;
		for (int pos = -1; ; ) {
			pos = problem.find(ch, pos + 1);
			if (pos < 0) break;
			answer[pos] = ch;	// 현재 단어를 갱신(맞힌 문자 열기)
			nMatched++;
		}
		return nMatched;
	}
	void guess() {
		char ch = getch();
		if (ch >= 'a' && ch <= 'z') {
			int pos = guessed.find(ch);
			if (pos < 0) {			// 아직 추측하지 않은 문자
				guessed[ch - 'a'] = ch;	// 예측한 문자 해당 위치 열기
				if (countMatched(ch) == 0) nTries++; // 실패 횟수 증가
			}
		}
	}
public:
	void play(string prob) {
		load();
		problem = prob;
		answer = string(problem.length(), '-');	// 생성자 사용(7장)
		guessed = string(24, '.');			// 생성자 사용(7장)
		nTries = 0;
		while (nTries < maxTries && answer != problem) {
			print();
			guess();
		}
		print();
		cout << "\n\t" << ((nTries == maxTries) ? "실패" : "정답") << endl;
	}
};