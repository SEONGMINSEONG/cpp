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
	//void add(Vector a, Vector b) {
	//	for (int i = 0; i < dim; i++)
	//		arr[i] = a.arr[i] + b.arr[i];
	//}
	void add(Vector* a, Vector* b) {
		for (int i = 0; i < dim; i++)
			arr[i] = a->arr[i] + b->arr[i];
	}

};
void main()
{
	Vector	u(3), v(3), w(3);
	u.setRand();
	v.setRand();
	u.print(" U ");
	v.print(" V ");
	//w.add(u, v);
	w.add(&u, &v);
	w.print("U+V");
}
