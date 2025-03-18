#include <cstdio>
void main()
{
	int n, i, k, count = 0; 		// 변수 선언. count는 0으로 초기화

	printf("소수를 구할 최대 숫자를 입력하시오 : ");
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {		// 2~n사이의 모든 수에 대해 
		for (k = 2; k<i; k++)		// 2부터 그 수보다 작은 수에 k로 
			if (i%k == 0) break;	// 나누어떨어지면 루프를 빠져나감
		if (k == i) {				// 나누어떨어지는 수가 없었으면
			printf("%4d ", i);	// 소수이므로 출력하고
			count++;				// count를 증가시킴
		}
	}
	printf("\n2~%d사이의 소수의 개수는 %d개 입니다.\n\n", n, count);
}