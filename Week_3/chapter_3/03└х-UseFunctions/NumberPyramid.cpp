#include <cstdio>
void printNumPyramid(int height)
{
	for (int i = 1; i <= height; i++) {
		for (int j = 0; j<height - i; j++)
 			printf("   ");	//°ø¹é 3°³
 		for (int j = 0; j<i; j++)
 			printf("%3d", j * 2 + 1);
 		for (int j = i - 2; j >= 0; j--)
 			printf("%3d", j * 2 + 1);
 		printf("\n");
	}
}