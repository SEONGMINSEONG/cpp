#include 	<cstdio>

int& getCount() {
	static int count = 0;
	count++;
	// ... 함수 내에서 처리할 코드
	return count;
}
void main()
{
	for (int i = 0; i<5; i++)
		printf("count = %d\n", getCount());
	getCount() = 10;		// getCount()내의 정적 변수 count에 10을 복사
	for (int i = 0; i<5; i++)
		printf("count = %d\n", getCount());
}