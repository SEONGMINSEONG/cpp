inline bool isPrimeNumber(int n) {
	for (int i = 2; i<n; i++)
		if (n%i == 0) return false;
	return true;
}
int getNextPrime() {
	static int prime = 1;
	//int prime = 1;
	while (isPrimeNumber(++prime) == false);
	return prime;
}
#include <stdio.h>
void main()
{
	for (int i = 0; i<10; i++) {
		printf("%d", getNextPrime());
		getchar();
	}
}