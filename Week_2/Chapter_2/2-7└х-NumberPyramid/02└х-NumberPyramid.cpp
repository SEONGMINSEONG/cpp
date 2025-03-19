#include <cstdio>
void main()
{
	int 	height;

	printf("높이를 입력하세요: ");
	scanf("%d", &height);
	for (int i = 1; i <= height; i++) {
		for (int j = 0; j<height - i; j++)
			printf("   ");			// 공백 출력
		for (int j = 0; j<i; j++)
			printf("%3d", j * 2 + 1);	// 증가하는 숫자 출력
		for (int j = i - 2; j >= 0; j--)
			printf("%3d", j * 2 + 1);	// 감소하는 숫자 출력
		printf("\n");				// 다음 줄로 이동
	}
}