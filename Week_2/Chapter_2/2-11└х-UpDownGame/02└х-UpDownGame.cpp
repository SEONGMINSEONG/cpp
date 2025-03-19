#include <stdio.h>
#include <conio.h>
void main()
{
	int	n, min = 1, max = 99, input, i;

	printf("두 자리 수 입력(1~99): ");
	char a = getch();
	printf("*");
	char b = getch();
	printf("*\n\n");
	n = (a - '0') * 10 + (b - '0');

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
	printf("  %s !!!  정답은 %d\n", (n == input) ? "성공" : "실패", n);
	printf("  최종 점수 = %d\n", 10 * (10 - i));
}