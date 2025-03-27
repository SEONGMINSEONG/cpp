#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void randomap(int map[5][5]) {
    srand(time(0)); 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2; 
        }
    }
}


void pritmap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == 1)
                cout << "● "; 
            else
                cout << "○ "; 
        }
        cout << endl;
    }
}


bool isSame(int arr[5], int value) {
    for (int i = 0; i < 5; i++) {
        if (arr[i] != value) return false;
    }
    return true;
}


void checkmap(int map[5][5]) {
    bool found = false;

    
    for (int i = 0; i < 5; i++) {
        if (isSame(map[i], 0) || isSame(map[i], 1)) {
            cout << "가로 " << i + 1 << "번째 줄이 " << map[i][0] << "로 채워짐" << endl;
            found = true;
        }
    }

   
    for (int j = 0; j < 5; j++) {
        int col[5];
        for (int i = 0; i < 5; i++) {
            col[i] = map[i][j];
        }
        if (isSame(col, 0) || isSame(col, 1)) {
            cout << "세로 " << j + 1 << "번째 줄이 " << col[0] << "로 채워짐" << endl;
            found = true;
        }
    }

   
    int diag1[5];
    for (int i = 0; i < 5; i++) {
        diag1[i] = map[i][i];
    }
    if (isSame(diag1, 0) || isSame(diag1, 1)) {
        cout << "좌상 → 우하 대각선이 " << diag1[0] << "로 채워짐" << endl;
        found = true;
    }

    
    int diag2[5];
    for (int i = 0; i < 5; i++) {
        diag2[i] = map[4 - i][i];
    }
    if (isSame(diag2, 0) || isSame(diag2, 1)) {
        cout << "좌하 → 우상 대각선이 " << diag2[0] << "로 채워짐" << endl;
        found = true;
    }

    if (!found) {
        cout << "가로, 세로, 대각선 중 같은 숫자로 가득 찬 줄이 없음" << endl;
    }
}

int main() {
    int map[5][5]; 

    randomap(map);  
    pritmap(map);   
    cout << endl;
    checkmap(map);  

    return 0;
}
