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

int main() {
    int map[5][5]; 

    randomap(map); 
    pritmap(map);  

    return 0;
}
