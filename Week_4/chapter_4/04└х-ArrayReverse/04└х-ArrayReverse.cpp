#include <cstdio>
#include <cstring>
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
void reverseString(const char src[], char dst[]) {
	int len = strlen(src);
	for (int i = 0; i < len; i++)
		dst[len - i - 1] = src[i];
	dst[len] = '\0';
}
void main()
{
	int a[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int b[10];
	char src[] = "game over !", dst[40];

	reverseArray(a, b, 10);
	reverseString(src, dst);
	printArray(a, 10, "배열 a");
	printArray(b, 10, "배열 b");
	printf("src = %s\n", src);
	printf("dst = %s\n", dst);
}