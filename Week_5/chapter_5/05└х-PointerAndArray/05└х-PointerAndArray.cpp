#include <stdio.h>
void main()
{
	int list[5] = { 1, 2, 3, 4, 5 };
	int* p = list, sum=0;

	printf("list= ");
	for (int i = 0; i < 5; i++)
		printf("%d ", *p++);			// 포인터 연산

	p = list;						// 포인터에 배열 주소 복사
	for (int i = 0; i < 5; i++)
		sum += p[i];					// 포인터에 항목 추출 연산자 적용
	printf("\nsum = %d\n", sum);
}