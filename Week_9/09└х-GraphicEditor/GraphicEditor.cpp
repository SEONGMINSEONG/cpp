#include "Shapes.h"
int main()
{
	Canvas myCanvas(25, 15);
	Line	l(2, 2, 8, 4);
	Rect	r(2, 9, 6, 3);
	HLine	h(1, 7, 23);
	VLine	v(12, 1, 13);
	Square	s(17, 1, 4);
	Circle	c(19, 11, 2);

	do {
		myCanvas.clear();
		l.draw(myCanvas, "��");
		r.draw(myCanvas, "��");
		v.draw(myCanvas, "��");
		h.draw(myCanvas, "--");
		s.draw(myCanvas, "��");
		c.draw(myCanvas);
		myCanvas.print("���� ������� �׸���");

		l.move(rand() % 3 - 1, rand() % 3 - 1);
		r.move(rand() % 3 - 1, rand() % 3 - 1);
		s.move(rand() % 3 - 1, rand() % 3 - 1);
		c.move(rand() % 3 - 1, rand() % 3 - 1);
	} while (getchar() != 'q');
}