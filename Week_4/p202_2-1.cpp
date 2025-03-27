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

void printMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int map[5][5]; 

    randomap(map); 
    printMap(map); 

    return 0;
}
