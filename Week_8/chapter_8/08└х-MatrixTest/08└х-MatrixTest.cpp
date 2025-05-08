#include "Matrix.h"
int findMaxPixel(int** a, int rows, int cols) {
	int max = a[0][0];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (max < a[i][j]) max = a[i][j];
	return max;
}
void main()
{
	Matrix u(3, 6);
	u.setRand();
	u.print(" U  = ");
	cout << "Max Pixel Value = "
		<< findMaxPixel(u.Data(), u.Rows(), u.Cols())
		<< endl;
}