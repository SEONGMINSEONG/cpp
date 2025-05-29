#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
	int	rows, cols;
	int**	mat;
public:
	Matrix(int xMax = 0, int yMax = 0) : rows(yMax), cols(xMax), mat(NULL) {
		mat = new int*[rows];
		for (int i = 0; i<rows; i++)
			mat[i] = new int[cols];
	}
	~Matrix() {
		for (int i = 0; i<rows; i++)
			delete[] mat[i];
		delete[] mat;
	}
	int&	operator()(int x, int y) { return mat[y][x]; }
	void print(char *str = "matrix") {
		cout << str << " " << rows << "x" << cols << endl;
		for (int i = 0; i<rows; i++) {
			for (int j = 0; j<cols; j++)
				cout << setw(4) << mat[i][j];
			cout << "\n";
		}
	}
};
void main()
{
	Matrix m(3, 2);
	m(0, 0) = 0;	m(1, 0) = 1;	m(2, 0) = 2;
	m(0, 1) = 3;	m(1, 1) = 4;	m(2, 1) = 5;
	m.print();
}