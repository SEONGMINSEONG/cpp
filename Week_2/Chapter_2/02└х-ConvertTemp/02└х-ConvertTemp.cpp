#include <stdio.h>
void main()
{
	int 	choice;
	double	F, C;

	printf("¿Âµµ º¯È¯Á¾·ù ¼±ÅÃ.\n");
	printf(" 1: C->F, 2: F->C ==> ");
	scanf("%d", &choice);

	if (choice == 1) {	// ¼·¾¾ -> È­¾¾
		printf(" ¼·¾¾¿Âµµ ÀÔ·Â: ");
		scanf("%lf", &C);
		F = C * 9.0 / 5 + 32.;
		printf(" È­¾¾¿Âµµ °è»ê: %6.1f\n", F);
	}

	if (choice == 2) {	// È­¾¾ -> ¼·¾¾
		printf(" È­¾¾¿Âµµ ÀÔ·Â: ");
		scanf("%lf", &F);
		C = (F - 32) * (5.0 / 9.0);
		printf(" ¼·¾¾¿Âµµ °è»ê: %6.1f\n", C);
	}
}