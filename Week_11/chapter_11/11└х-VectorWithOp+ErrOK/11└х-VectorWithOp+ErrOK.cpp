#include <iostream>
using namespace std;

class Vector {
	double* 	arr;
	int 	dim;
public:
	Vector(int d = 0) : dim(d), arr(NULL) { arr = new double[dim]; }
	~Vector() { delete[] arr; }
	double& operator[] (int id) { return arr[id]; }
	friend ostream& operator << (ostream& os, Vector& v) {
		os << "<";
		for (int i = 0; i < v.dim; i++)
			os << v.arr[i] << " ";
		os << ">";
		return os;
	}
	void add(Vector& u, Vector& v) {
		for (int i = 0; i < dim; i++)
			arr[i] = u[i] + v[i];
	}

	Vector operator + (Vector& v) {
		Vector sum(v.dim);
		for (int i = 0; i < dim; i++)
			sum[i] = arr[i] + v[i];	// v[i]는 v.arr[i]와 동일. [ ]중복
		return sum;
	}

	Vector& operator = (Vector& v) {		// 대입연산자 중복
		clone(v);
		return *this;
	}
	void clone(Vector& a) {			// 깊은 복사를 위한 clone 함수
		if (dim > 0) delete[] arr;
		dim = a.dim;
		arr = new double[dim];
		for (int i = 0; i < dim; i++)
			arr[i] = a.arr[i];
	}
	Vector(Vector& v) : arr(NULL) { clone(v); }// 복사 생성자
};

void main()
{
	Vector	u(4), v(4), w(4);
	for (int i = 0; i < 4; i++) {
		u[i] = i*10.0;
		v[i] = i;
	}
	cout << " u  = " << u << endl;
	cout << " v  = " << v << endl;
	//w.add(u, v);
	w = u + v;
	cout << "u+v = " << w << endl;
}