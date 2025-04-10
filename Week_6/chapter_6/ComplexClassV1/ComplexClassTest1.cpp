#include "Complex.h"

void main()
{
	Complex a, b, c;

	a.readComplex ( "A =" );
	b.readComplex ( "B =" );
	c.addComplex (a, b);

	a.printComplex( "  A  = ");
	b.printComplex( "  B  = ");
	c.printComplex( " A+B = ");
}