#include <iostream>		// #include <stdio.h> 
using namespace std;

void main()
{
	int x, y;
	cout << "두 정수 입력: ";		// printf("두 정수 입력: ");
	cin >> x >> y;			// scanf("%d%d", &x, &y);
	cout << " x=" << x << " y=" << y	// printf(" x=%d y=%d x+y=%d\n",
		<< " x+y=" << x + y << endl;	//		x, y, x+y);
}