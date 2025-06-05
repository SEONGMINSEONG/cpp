#pragma once
#include <string>
struct FileException {	// 파일 예외 클래스
	string filename;		// 파일 이름
	bool bRead;		// 파일 모드
	FileException(string name, bool b) : filename(name), bRead(b) {}
};