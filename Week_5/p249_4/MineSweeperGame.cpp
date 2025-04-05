#include <stdio.h>      
#include <stdlib.h>    
#include <string.h>    
#include <time.h>      
#include <ctype.h>     
#include <termios.h>    
#include <unistd.h>     

int nx, ny;             // 맵의 가로(nx)와 세로(ny) 크기를 저장하는 전역 변수
int nBomb;              // 게임에 배치할 지뢰 개수를 저장하는 전역 변수
static int MineMapMask[40][80];   // 맵의 상태를 저장 (숨김/열림/깃발)
static int MineMapLabel[40][80];  // 맵의 내용을 저장 (빈칸/지뢰/주변 지뢰 수)

// 맵의 칸 상태를 정의 (숫자로 표현)
enum LabelType { Empty = 0, Bomb = 9 };  // 빈칸은 0, 지뢰는 9
enum MaskType { Hide = 0, Open, Flag };  // 숨김은 0, 열림은 1, 깃발은 2

// 편리하게 맵의 특정 위치를 접근하기 위한 함수들
inline int& mask(int x, int y) { return MineMapMask[y][x]; }  // 맵의 상태(숨김/열림/깃발) 반환
inline int& label(int x, int y) { return MineMapLabel[y][x]; } // 맵의 내용(빈칸/지뢰/숫자) 반환
inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); } // 좌표가 맵 안에 있는지 확인
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }     // 해당 위치가 지뢰인지 확인
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }   // 해당 위치가 빈칸인지 확인

// 칸을 여는 함수 (주변 빈칸도 자동으로 열림)
static void dig(int x, int y) {
    if (isValid(x, y) && mask(x, y) != Open) { // 유효한 좌표이고 아직 열리지 않았다면
        mask(x, y) = Open; // 해당 칸을 열림 상태로 변경
        if (label(x, y) == 0) { // 주변에 지뢰가 없으면(빈칸이면)
            // 주변 8칸을 재귀적으로 열기
            dig(x - 1, y - 1); dig(x - 1, y); dig(x - 1, y + 1);
            dig(x, y - 1);     dig(x, y + 1);
            dig(x + 1, y - 1); dig(x + 1, y); dig(x + 1, y + 1);
        }
    }
}

// 깃발을 설치하는 함수
static void mark(int x, int y) {
    if (isValid(x, y) && mask(x, y) == Hide) // 유효한 좌표이고 숨겨진 상태라면
        mask(x, y) = Flag; // 깃발 설치
}

// 설치된 깃발 개수를 세는 함수
static int getBombCount() {
    int count = 0;
    for (int y = 0; y < ny; y++) // 세로 전체를 순회
        for (int x = 0; x < nx; x++) // 가로 전체를 순회
            if (mask(x, y) == Flag) count++; // 깃발이 있으면 카운트 증가
    return count; // 깃발 개수 반환
}

// 게임 화면을 출력하는 함수
static void print(bool gameOver) {
    system("clear"); // 터미널 화면을 지움 (리눅스/유닉스 환경)
    printf("\n=== 지뢰 찾기 ===\n");
    printf("발견한 지뢰: %d / 총 지뢰: %d\n\n", getBombCount(), nBomb); // 깃발 수와 지뢰 수 표시
    printf("    ");
    for (int x = 0; x < nx; x++) // 열 번호 출력
        printf("%3d", x + 1);
    printf("\n    ");
    for (int x = 0; x < nx; x++) // 구분선 출력
        printf("---");
    printf("\n");
    for (int y = 0; y < ny; y++) { // 각 행을 순회
        printf("%2d | ", y + 1); // 행 번호 출력
        for (int x = 0; x < nx; x++) { // 각 열을 순회
            if (gameOver && isBomb(x, y)) printf("💣 "); // 게임 오버 시 지뢰 표시
            else if (mask(x, y) == Hide) printf("⬜ ");  // 숨겨진 칸은 네모로
            else if (mask(x, y) == Flag) printf("🚩 ");  // 깃발은 깃발 아이콘으로
            else { // 열린 칸의 경우
                if (isBomb(x, y)) printf("💣 "); // 지뢰면 폭탄 표시
                else if (isEmpty(x, y)) printf("   "); // 빈칸이면 공백
                else printf("%2d ", label(x, y)); // 숫자면 주변 지뢰 수 표시
            }
        }
        printf("|\n"); // 행 끝 구분선
    }
    printf("    ");
    for (int x = 0; x < nx; x++) // 하단 구분선 출력
        printf("---");
    printf("\n");
}

// 주변 지뢰 개수를 세는 함수
static int countNbrBombs(int x, int y) {
    int count = 0;
    for (int yy = y - 1; yy <= y + 1; yy++) // 주변 3x3 영역을 확인
        for (int xx = x - 1; xx <= x + 1; xx++)
            if (isValid(xx, yy) && label(xx, yy) == Bomb) // 지뢰가 있으면 카운트 증가
                count++;
    return count; // 주변 지뢰 개수 반환
}

// 게임 맵을 초기화하는 함수
static void init(int total) {
    srand((unsigned int)time(NULL)); // 난수 생성을 위해 현재 시간 설정
    for (int y = 0; y < ny; y++) // 모든 칸을 초기화
        for (int x = 0; x < nx; x++) {
            mask(x, y) = Hide; // 모든 칸을 숨김 상태로
            label(x, y) = 0;   // 모든 칸을 빈칸으로
        }
    nBomb = total; // 지뢰 개수 설정
    for (int i = 0; i < nBomb; i++) { // 지뢰를 무작위로 배치
        int x, y;
        do {
            x = rand() % nx; // 무작위 열 선택
            y = rand() % ny; // 무작위 행 선택
        } while (label(x, y) != Empty); // 빈칸이 아닌 경우 다시 선택
        label(x, y) = Bomb; // 지뢰 배치
    }
    for (int y = 0; y < ny; y++) // 각 칸의 주변 지뢰 수 계산
        for (int x = 0; x < nx; x++)
            if (label(x, y) == Empty)
                label(x, y) = countNbrBombs(x, y); // 빈칸에 숫자 기록
}

// 사용자로부터 입력을 받는 함수
static bool getPos(int& x, int& y) {
    char input[10];
    printf("\n지뢰(P)행(1-%d)열(1-%d)\n입력--> ", ny, nx); // 입력 안내
    scanf("%s", input); // 첫 번째 입력(행 번호 또는 P+행 번호)
    bool isBomb = (input[0] == 'P' || input[0] == 'p'); // P로 시작하면 깃발 설치
    int offset = isBomb ? 1 : 0; // P가 있으면 한 칸 건너뜀
    y = atoi(input + offset) - 1; // 행 번호를 숫자로 변환 (1부터 시작하므로 -1)
    scanf("%d", &x); // 열 번호 입력
    x -= 1; // 열 번호도 1부터 시작하므로 -1
    return isBomb; // 깃발 설치 여부 반환 (true면 깃발, false면 열기)
}

// 게임 종료 조건을 확인하는 함수
static int checkDone() {
    for (int y = 0; y < ny; y++) // 지뢰를 밟았는지 확인
        for (int x = 0; x < nx; x++)
            if (mask(x, y) == Open && isBomb(x, y))
                return -1; // 지뢰 폭발 시 실패

    int flaggedBombs = 0; // 깃발로 표시된 지뢰 개수
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (isBomb(x, y) && mask(x, y) == Flag) // 지뢰에 깃발이 있으면
                flaggedBombs++; // 카운트 증가
            else if (!isBomb(x, y) && mask(x, y) == Flag) // 지뢰 아닌 곳에 깃발이면
                return 0; // 아직 성공 아님
        }
    }
    if (flaggedBombs == nBomb) return 1; // 모든 지뢰에 깃발이 설치되면 성공
    return 0; // 게임 진행 중
}

// 게임을 실행하는 함수
void playMineSweeper(int total) {
    int x, y, status;
    init(total); // 맵 초기화
    do {
        print(false); // 게임 화면 출력 (게임 중이므로 gameOver=false)
        bool isBomb = getPos(x, y); // 사용자 입력 받기
        if (isBomb) mark(x, y); // 깃발 설치
        else dig(x, y); // 칸 열기
        status = checkDone(); // 게임 상태 확인
    } while (status == 0); // 진행 중이면 반복
    print(status < 0); // 최종 화면 출력 (실패 시 지뢰 표시)
    if (status < 0)
        printf("\n실패: 지뢰 폭발!!!\n\n"); // 실패 메시지
    else
        printf("\n성공: 모든 지뢰를 찾았습니다!!!\n\n"); // 성공 메시지
}

// 게임 시작 함수
int main() {
    int total; // 지뢰 개수를 저장할 변수
    printf(" <Mine Sweeper>\n");
    printf(" 지뢰 맵의 가로 크기 (최대 80): ");
    scanf("%d", &nx); // 가로 크기 입력
    if (nx > 80) nx = 80; // 최대 80 제한
    if (nx < 1) nx = 1;   // 최소 1 보장
    printf(" 지뢰 맵의 세로 크기 (최대 40): ");
    scanf("%d", &ny); // 세로 크기 입력
    if (ny > 40) ny = 40; // 최대 40 제한
    if (ny < 1) ny = 1;   // 최소 1 보장
    printf(" 배치할 총 지뢰의 개수 입력 : ");
    scanf("%d", &total); // 지뢰 개수 입력
    if (total >= nx * ny) total = nx * ny - 1; // 맵 크기보다 많으면 조정
    if (total < 0) total = 0; // 음수면 0으로
    playMineSweeper(total); // 게임 시작
    return 0; // 프로그램 종료
}