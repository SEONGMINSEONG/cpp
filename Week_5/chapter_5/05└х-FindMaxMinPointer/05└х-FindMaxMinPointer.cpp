#include 	<cstdio>
void findMinMax(int* a, int len, int* pmin, int* pmax) {
	if (pmin != NULL) {
		*pmin = a[0];
		for (int i = 1; i < len; i++)
			if (*pmin > a[i]) *pmin = a[i];
	}
	if (pmax != NULL) {
		*pmax = a[0];
		for (int i = 1; i < len; i++)
			if (*pmax < a[i]) *pmax = a[i];
	}
}
void main()
{
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int min, max;

	findMinMax(arr, 10, &min, &max);
	printf("ÃÖ¼Ò~ÃÖ´ë: %2d~ %2d\n", min, max);

	findMinMax(arr, 10, &min, NULL);
	printf("ÃÖ¼Ú°ª: %2d\n", min);

	findMinMax(arr, 10, NULL, &max);
	printf("ÃÖ´ñ°ª: %2d\n", max);
}