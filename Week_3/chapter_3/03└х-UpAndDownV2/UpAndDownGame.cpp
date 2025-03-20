#include <stdio.h>
#include <conio.h>
int playUpAndDown(int n, int min, int max)
{
	int	input, i;
 	for (i = 0; i<10; i++) {
 		printf("[%2d회] %2d ~ %2d 사이의 값 예측 =>", i + 1, min, max);
 		scanf("%d", &input);

 		if (n == input) break;
		else if (n > input) {
			printf(" 더 큰 숫자입니다!\n");
			min = input;
		}
 		else {
 			printf(" 더 작은 숫자입니다!\n");
 			max = input;
		}
	}
	return 10 * (10-i);
}
