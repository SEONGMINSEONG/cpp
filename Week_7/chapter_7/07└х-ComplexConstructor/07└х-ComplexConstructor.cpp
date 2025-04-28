
/*
class Complex {
	double real, imag; 		// 멤버 변수. 실수부와 허수부
public:
	Complex() { real = imag = 0.0; } 	// 기본 생성자
	Complex(double r, double i) { 	// 매개 변수가 있는 생성자
		real = r;		// r을 멤버 변수 real에 복사
		imag = i;		// i를 멤버 변수 imag에 복사
	}
	//...				// 여러 가지 멤버 함수 추가
};

class Complex {
	double real, imag;
public:
	Complex(double r = 0, double i = 0) { 	// 디폴트 생성자 겸용 생성자
		real = r;		// r을 멤버 변수 real에 복사
		imag = i;		// i를 멤버 변수 imag에 복사
	}
	//...
};
*/

class Complex {
	double real, imag;
public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) { }
	//...
};

void main() { }