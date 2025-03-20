#include <stdio.h>
int factorial(int);		// factorial()함수의 원형 선언
int add(int, int);		// add()함수의 원형 선언
void main()
{
	int x = 3, y = 4, z;
	z = add(x, y);
	printf("x + y  = %d\n", z);
	printf("x + 10 = %d\n", add(x, 10));	// 변수와 상수 전달
	printf("5 + 10 = %d\n", add(5, 10)); 	// 두 상수 전달

	z = factorial(x);					// 3!를 계산해 z에 대입
	printf("%d! = %d\n", x, z);			// z를 화면에 출력
	printf("5! = %d\n", factorial(5));	// 5!를 계산해 화면으로 출력
}
// 프로그램 3.2의 모든 코드 추가

int add(int a, int b) 		// 두 int값을 더해 반환하는 함수
{
	int sum;					// 결과 값을 저장할 변수 선언
	sum = a + b;				// a 와 b를 더해 sum에 대입함
	return sum;				// 결과 값인 sum을 반환
}
int factorial(int n)			// n!을 구하는 함수
{
	int result = 1;			// 결과 값을 저장할 변수 선언 및 초기화
	for (int i = 1; i <= n; i++)// i를 1부터 n까지 1씩 증가하면서 반복문 수행
		result *= i;			// result에 i를 곱함
	return result;			// 결과 값인 result를 반환
}