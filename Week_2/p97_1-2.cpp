#include <iostream>
using namespace std;

int main() 
{
    for (int i = 5; i >= 1; i--) {
        for (int j = 5; j >= 6 - i; j--) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
