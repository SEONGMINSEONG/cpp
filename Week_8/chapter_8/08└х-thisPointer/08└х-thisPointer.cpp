#include <cstdio>
class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	void print(char* msg = "P=") {
		printf("%s(%d,%d)\n", msg, this->x, this->y);
	}
	void whereAmI() {
		printf("аж╪р=%x\n", this);
	}
};
void main()
{
	Point	p(1, 2), q(3, 4);
	p.print(" P = ");
	p.whereAmI();
	q.print(" Q = ");
	q.whereAmI();
}