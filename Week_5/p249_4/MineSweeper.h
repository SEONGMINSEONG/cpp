#pragma once            // 이 파일이 여러 번 포함되지 않도록 보장 (중복 방지용)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
// 지뢰 찾기 게임을 실행하는 함수 선언
// 외부 파일에서 사용할 수 있도록 'extern' 키워드 사용
extern void playMineSweeper(int total); // total: 배치할 지뢰 개수, 이 함수가 게임을 시작함