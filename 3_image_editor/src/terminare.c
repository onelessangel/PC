#include "alocari.h"

void terminare(short int exista_fisier, int linii, unsigned char ***mat)
{
	if (exista_fisier == 1) {
		if (*mat)
			elib_matr(mat, linii);
	} else {
		printf("No image loaded\n");
	}
}