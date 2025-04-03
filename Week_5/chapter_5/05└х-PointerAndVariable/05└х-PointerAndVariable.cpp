#include <stdio.h>
void main()
{
	int x = 10;
	int* px = &x;
	int** ppx = &px;
	printf("  변수   x 값   = %d = %d = %d\n", x, *px, **ppx);
	printf("  변수   x 주소 = 0x%x = 0x%x = 0x%x\n", &x, px, *ppx);
	printf("포인터  px 주소 = 0x%x = 0x%x\n", &px, ppx);
	printf("포인터 ppx 주소 = 0x%x\n", &ppx);
	*px = 20;
	printf("  변수   x 값   = %d = %d = %d\n", x, *px, **ppx);
}