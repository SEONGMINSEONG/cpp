#include <iostream>
using namespace std;

class Vector {
	int dim;		// 벡터의 차원
	double* arr;	// 벡터의 각 차원 데이터
public:
	Vector(int d = 0) : dim(d) { arr = new double[dim]; }
	~Vector() { delete[] arr; }

	void setRand(int max = 100) {
		for (int i = 0; i<dim; i++)
			arr[i] = rand() % (max * 10) / 10.0;
	}
	void print(char *str = "Vector") {
		cout << str << "[" << dim << "] = < ";
		for (int i = 0; i < dim; i++)
			cout << arr[i] << " ";
		cout << ">\n";
	}
	void clone(Vector& a) {
		if (dim > 0) delete[] arr;
		dim = a.dim;
		arr = new double[dim];
		for (int i = 0; i < dim; i++)
			arr[i] = a.arr[i];
	}
	void add(Vector a, Vector b) {
		for (int i = 0; i < dim; i++)
			arr[i] = a.arr[i] + b.arr[i];
	}
	void operator = (Vector& a) { clone(a); }
	Vector(Vector& a) : dim(0) { clone(a); }
};
void main()
{
	Vector	u(3), v, w(3);
	u.setRand();
	v = u;
	w.add(u, v);
	u.print(" U ");
	v.print(" V ");
	w.print("U+V");
}