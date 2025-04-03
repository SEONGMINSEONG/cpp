#include <cstdio>
int findMaxValue(int* a, int len) {
	int maxVal = a[0];
	for (int i = 1; i<len; i++)
		if (maxVal < a[i]) maxVal = a[i];
	return maxVal;
}
void main() {
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	printf("max val  = %d\n", findMaxValue(arr, 10));
}