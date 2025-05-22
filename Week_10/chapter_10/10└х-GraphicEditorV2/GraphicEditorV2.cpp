#include "Shapes.h"

void main()
{
	Canvas myCanvas(25, 15);
	Line*	lList[100];
	VLine*	vList[100];
	HLine*	hList[100];
	Rect*	rList[100];
	Square*	sList[100];
	Circle*	cList[100];
	int	nLine = 0, nVLine = 0, nHLine = 0;
	int	nCircle = 0, nRect = 0, nSquare = 0;

	while (true) {
		myCanvas.print("  < 내 마음대로 그릴 수 있는 나의 그래픽 편집기 >");
		char str[200], type;
		int v[4];
		printf("Input ==> ");
		gets_s(str);			// VC2015부터는 get_s() 사용
		int ret = sscanf(str, "%c%d%d%d%d", &type, v, v + 1, v + 2, v + 3);

		if (type == 'l' && ret == 5)
			lList[nLine++] = new Line(v[0], v[1], v[2], v[3]);
		else if (type == 'v' && ret == 4)
			vList[nVLine++] = new VLine(v[0], v[1], v[2]);
		else if (type == 'h' && ret == 4)
			hList[nHLine++] = new HLine(v[0], v[1], v[2]);
		else if (type == 'c' && ret == 4)
			cList[nCircle++] = new Circle(v[0], v[1], v[2]);
		else if (type == 'r' && ret == 5)
			rList[nRect++] = new Rect(v[0], v[1], v[2], v[3]);
		else if (type == 's' && ret == 4)
			sList[nSquare++] = new Square(v[0], v[1], v[2]);
		else if (type == 'q') break;

		myCanvas.clear(". ");
		for (int i = 0; i < nLine; i++) lList[i]->draw(myCanvas, "●");
		for (int i = 0; i < nVLine; i++) vList[i]->draw(myCanvas, "∥");
		for (int i = 0; i < nHLine; i++) hList[i]->draw(myCanvas, "--");
		for (int i = 0; i < nCircle; i++) cList[i]->draw(myCanvas, "◎");
		for (int i = 0; i < nRect; i++) rList[i]->draw(myCanvas, "▣");
		for (int i = 0; i < nSquare; i++) sList[i]->draw(myCanvas, "■");
	}
	for (int i = 0; i < nLine; i++) delete lList[i];
	for (int i = 0; i < nVLine; i++) delete vList[i];
	for (int i = 0; i < nHLine; i++) delete hList[i];
	for (int i = 0; i < nCircle; i++) delete cList[i];
	for (int i = 0; i < nRect; i++) delete rList[i];
	for (int i = 0; i < nSquare; i++) delete sList[i];
}