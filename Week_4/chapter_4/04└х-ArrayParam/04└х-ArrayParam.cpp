#include <cstdio>
#include <cstring>
int findMaxValue(int a[], int len) {
	int maxVal = a[0];
	for (int i = 1; i<len; i++)
		if (maxVal < a[i]) maxVal = a[i];
	return maxVal;
}
char findMaxChar(char a[]) {
	char maxChar = a[0];
	for (int i = 1; i<strlen(a); i++)
		if (maxChar < a[i]) maxChar = a[i];
	return maxChar;
}
void main() {
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	char str[] = "geme over !";
	printf("max val  = %d\n", findMaxValue(arr, 10));
	printf("max char = %c\n", findMaxChar(str));
}