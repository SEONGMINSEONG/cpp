#include <cstdio>
#include <cstring>
// 프로그램 4.4의 3~8행의 printArray()함수 추가
void printArray(const int a[], int len, char msg[] = "Array") {
	printf("%s: ", msg);
	for (int i = 0; i < len; i++)
		printf("%3d", a[i]);
	printf("\n");
}
void reverseArray(const int a[], int b[], int len) {
	for (int i = 0; i < len; i++)
		b[len - i - 1] = a[i];
}
int* reverseArray1(const int a[], int len) {
	int b[100];
	for (int i = 0; i < len; i++)
		b[len - i - 1] = a[i];
	return b;		// 잘못된 구현 방법
}
int* reverseArray2(const int a[], int len) {
	static int b[100];
	for (int i = 0; i < len; i++)
		b[len - i - 1] = a[i];
	return b;		// 여전히 문제가 있는 방법 
}
void main()
{
	int a[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int b[10], *c, *d;

	reverseArray(a, b, 10);
	c = reverseArray1(a, 10);
	d = reverseArray2(a, 10);

	printArray(a, 10, "배열 a");
	printArray(b, 10, "배열 b");
	printArray(c, 10, "배열 c");
	printArray(d, 10, "배열 d");
}