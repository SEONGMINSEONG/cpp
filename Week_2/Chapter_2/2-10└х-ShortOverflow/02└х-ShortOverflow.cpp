#include <cstdio>
void main()
{
	short n = 0;
loop:
	n = n + 1;
	if (n > 0) {
		printf("\r short 최댓값 = %d", n);
		goto loop;
	}
	printf("\n오버플로우 발생\a\n");
	printf(" short 최솟값 = %d\n", n);
}