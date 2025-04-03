#include 	<cstdio>
void findMinMax(int* a, int len, int& min, int& max) {
	min = a[0];
	for (int i = 1; i < len; i++)
		if (min > a[i]) min = a[i];

	max = a[0];
	for (int i = 1; i < len; i++)
		if (max < a[i]) max = a[i];
}
void main()
{
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int x, y;

	findMinMax(arr, 10, x, y);
	printf("최소~최대: %2d~ %2d\n", x, y);
}