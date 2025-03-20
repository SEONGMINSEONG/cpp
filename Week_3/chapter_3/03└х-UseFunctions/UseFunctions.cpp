#include <stdio.h>
#include "myFunctions.h"
void main()
{
	printf("¼·¾¾ %5.1fµµ = È­¾¾ %5.1fµµ\n", 27.0, Celcius2Fahrenheit(27.0));
	printf("È­¾¾ %5.1fµµ = ¼·¾¾ %5.1fµµ\n", 95.0, Fahrenheit2Celcius(95.0));
	printNumPyramid(5);
	printf("°ÔÀÓ Á¡¼ö = %d\n", playUpAndDown(35, 0, 99));
}

