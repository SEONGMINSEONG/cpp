#include "Shapes.h"
void main()
{
	Canvas myCanvas(25, 15);
	Shape*	list[100];
	int	nShape = 0;

	while (true) {
		myCanvas.print("  < 내 마음대로 그릴 수 있는 나의 그래픽 편집기 >");
		char str[200], type;
		int	v[4];
		printf("Input ==> ");
		gets_s(str);
		int ret = sscanf(str, "%c%d%d%d%d", &type, v, v + 1, v + 2, v + 3);

		if (type == 'l' && ret == 5)
			list[nShape++] = new Line(v[0], v[1], v[2], v[3]);
		else if (type == 'v' && ret == 4)
			list[nShape++] = new VLine(v[0], v[1], v[2]);
		else if (type == 'h' && ret == 4)
			list[nShape++] = new HLine(v[0], v[1], v[2]);
		else if (type == 'c' && ret == 4)
			list[nShape++] = new Circle(v[0], v[1], v[2]);
		else if (type == 'r' && ret == 5)
			list[nShape++] = new Rect(v[0], v[1], v[2], v[3]);
		else if (type == 's' && ret == 4)
			list[nShape++] = new Square(v[0], v[1], v[2]);
		else if (type == 'q') break;

		myCanvas.clear(". ");
		for (int i = 0; i < nShape; i++)
			list[i]->draw(myCanvas);
	}
	for (int i = 0; i < nShape; i++)
		delete list[i];
}