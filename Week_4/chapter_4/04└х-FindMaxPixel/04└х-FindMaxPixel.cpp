int findMaxPixel(int a[][5], int h, int w) {
	int maxVal = 0;
	for (int i = 0; i<h; i++)
		for (int j = 0; j<w; j++)
			if (maxVal < a[i][j])
				maxVal = a[i][j];
	return maxVal;
}
#include <cstdio>
void main()
{
	int img[3][5] = { { 3, 24, 82, 12, 22 },
	{ 99,  7, 65, 73, 58 },
	{ 20,  7,  9, 48, 29 } };
	int maxPixel = findMaxPixel(img, 3, 5);
	printf("영상의 최대 밝기 = %d\n", maxPixel);
}