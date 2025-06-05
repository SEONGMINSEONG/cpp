#include <iostream>
using namespace std;

void main()
{
	const double phi = 3.14;
	//phi = 3.5;		// Error: 상수 phi 값을 변경할 수 없음

	int x = 10, y = 20, z = 30, w = 40;
	int* px = &x;
	int* const py = &y;	// py 자체를 변경 불가
	const int* pz = &z;	// pz가 가리키는 주소의 값을 변경 불가
	const int* const pw = &w; // pw와 가리키는 주소의 값을 모두 변경 불가

	cout << " x=" << x << " y=" << y << " z=" << z << " w=" << w << endl;
	*px = 100;
	*py = 100;
	//*pz = 100;		// Error: pz가 가리키는 주소의 값을 변경할 수 없음
	//*pw = 100;		// Error: pw가 가리키는 주소의 값을 변경할 수 없음
	cout << " x=" << x << " y=" << y << " z=" << z << " w=" << w << endl;

	cout << " px=" << px << " py=" << py << " pz=" << pz << " pw=" << pw << endl;
	px = &y;
	pz = &w;
	//py = &x;		// Error: py의 값(주소)를 변경할 수 없음
	//pw = &z;		// Error: pw의 값(주소)를 변경할 수 없음
	cout << " *px=" << *px << " y=" << y << " *pz=" << *pz << " w=" << w << endl;
}