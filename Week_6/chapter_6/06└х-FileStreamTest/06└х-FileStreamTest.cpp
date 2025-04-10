#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	int x = 1, y = 2;
	char s[100];

	ofstream f1("tmp.txt"); 		// 저장을 위한 파일 열기
	if (f1) {			// 정상적으로 열렸으면
		f1 << x << " " << y << endl;	// 파일로 int 값 저장
		f1 << "Game Over !\n\n";	// 파일로 문자열 저장
	}
	f1.close();			// 파일 닫기

	ifstream f2("tmp.txt"); 		// 읽기를 위한 파일 열기
	if (f2) { 			// 정상적으로 열렸으면
		f2 >> x >> y; 		// 파일에서부터 x와 y 읽기
		f2 >> s; 			// 파일에서부터 문자열 읽기
		cout << " x=" << x << " y=" << y << endl;
		cout << s << endl;
	}
	f2.close();			// 파일 닫기
}