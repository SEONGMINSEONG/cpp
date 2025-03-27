#include <stdio.h>
#include <stdlib.h>

void fprintArray(int a[], int len, FILE* fp = stdout) {
	for (int i = 0; i < len; i++)
		fprintf(fp, "%d ", a[i]);
	fprintf(fp, "\n");
}
void main()
{
	FILE *fp;
	int a[10], b[10];

	for (int i = 0; i < 10; i++) a[i] = rand();

	printf(" 원본 데이터: ");
	fprintArray(a, 10);

	fp = fopen("아스키파일.txt", "w");
	if (fp != NULL) {
		fprintArray(a, 10, fp);
		fclose(fp);
	}
	fp = fopen("아스키파일.txt", "r");
	if (fp != NULL) {
		for (int i = 0; i < 10; i++)
			fscanf(fp, "%d", &(b[i]));
		printf(" 아스키 파일: ");
		fprintArray(b, 10);
		fclose(fp);
	}
}