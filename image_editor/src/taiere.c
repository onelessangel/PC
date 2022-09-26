#include "alocari.h"

int taiere(short int *selectie, int *x1, int *y1, int *x2, int *y2,
		   unsigned char ***mat, int *linii, int *coloane, unsigned char cifra)
{
	int d_l = *x2 - *x1;
	int d_c = *y2 - *y1;
	unsigned char **copie_mat;
	int color;

	if (cifra != '3' && cifra != '6')
		color = 0;
	else
		color = 1;

	if (!color) {
		copie_mat = aloc_matr_simpla(d_l + 1, d_c + 1);

		for (int i = 0; i <= d_l; i++)
			for (int j = 0; j <= d_c; j++)
				copie_mat[i][j] = (*mat)[*x1 + i][*y1 + j];

		elib_matr(mat, *linii);
		*mat = copie_mat;
		*linii = d_l + 1;
		*coloane = d_c + 1;

		copie_mat = NULL;
	} else {
		copie_mat = aloc_matr_simpla(d_l + 1, (d_c + 1) * 3);

		for (int i = 0; i <= d_l; i++)
			for (int j = 0; j < (d_c + 1) * 3; j++)
				copie_mat[i][j] = (*mat)[*x1 + i][*y1 * 3 + j];

		elib_matr(mat, *linii);
		*mat = copie_mat;
		*linii = d_l + 1;
		*coloane = (d_c + 1) * 3;
	}

	reselectare(x1, y1, x2, y2, *linii, *coloane, selectie, color);
}
