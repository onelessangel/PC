#include "alocari.h"

void r_90(int color, unsigned char ***mat, short int selectie, int d_c,
		  int d_l, int x1, int y1, int x2, int y2, int *linii, int *coloane)
{
	unsigned char **copie_mat;
	if (!color) {
		copie_mat = aloc_matr_simpla(d_c + 1, d_l + 1);

		for (int i = 0; i <= d_l; i++)
			for (int j = 0; j <= d_c; j++)
				copie_mat[j][d_l - i] = (*mat)[x1 + i][y1 + j];

		if (selectie == 0) {
			elib_matr(mat, *linii);
			*mat = copie_mat;
			*linii = d_c + 1;
			*coloane = d_l + 1;
		} else {
			for (int i = 0; i <= d_l; i++)
				for (int j = 0; j <= d_c; j++)
					(*mat)[x1 + i][y1 + j] = copie_mat[i][j];

			elib_matr(&copie_mat, d_c + 1);
		}

	} else {
		copie_mat = aloc_matr_simpla(d_c + 1, (d_l + 1) * 3);

		for (int i = 0; i <= d_l; i++) {
			for (int c = 0; c <= d_c; c++)
				for (int k = 0; k <= 2; k++)
					copie_mat[c][(d_l - i) * 3 + k] = (*mat)[x1 + i][y1 * 3 + c * 3 + k];
		}

		if (selectie == 0) {
			elib_matr(mat, *linii);
			*mat = copie_mat;
			*linii = d_c + 1;
			*coloane = (d_l + 1) * 3;
		} else {
			for (int i = 0; i <= d_l; i++)
				for (int j = 0; j < (d_c + 1) * 3; j++)
					(*mat)[x1 + i][y1 * 3 + j] = copie_mat[i][j];

			elib_matr(&copie_mat, d_c + 1);
		}
	}
}

void r_180(int color, unsigned char ***mat, short int selectie, int d_c,
		   int d_l, int x1, int y1, int x2, int y2, int *linii, int *coloane)
{
	unsigned char **copie_mat;
	if (!color) {
		copie_mat = aloc_matr_simpla(d_l + 1, d_c + 1);

		for (int i = 0; i <= d_l; i++)
			for (int j = 0; j <= d_c; j++)
				copie_mat[d_l - i][d_c - j] = (*mat)[x1 + i][y1 + j];

		if (selectie == 0) {
			elib_matr(mat, *linii);
			*mat = copie_mat;
			*linii = d_l + 1;
			*coloane = d_c + 1;
		} else {
			for (int i = 0; i <= d_l; i++)
				for (int j = 0; j <= d_c; j++)
					(*mat)[x1 + i][y1 + j] = copie_mat[i][j];

			elib_matr(&copie_mat, d_l + 1);
		}

	} else {
		copie_mat = aloc_matr_simpla(d_l + 1, (d_c + 1) * 3);

		for (int i = 0; i <= d_l; i++)
			for (int c = 0; c <= d_c; c++)
				for (int k = 0; k <= 2; k++)
					copie_mat[d_l - i][(d_c - c) * 3 + k] = (*mat)[x1 + i][y1 * 3 + c * 3 + k];

		if (selectie == 0) {
			elib_matr(mat, *linii);
			*mat = copie_mat;
			*linii = d_l + 1;
			*coloane = (d_c + 1) * 3;
		} else {
			for (int i = 0; i <= d_l; i++)
				for (int j = 0; j < (d_c + 1) * 3; j++)
					(*mat)[x1 + i][y1 * 3 + j] = copie_mat[i][j];

			elib_matr(&copie_mat, d_l + 1);
		}
	}
}

void r_270(int color, unsigned char ***mat, short int selectie, int d_c,
		   int d_l, int x1, int y1, int x2, int y2, int *linii, int *coloane)
{
	unsigned char **copie_mat;
	if (!color) {
		copie_mat = aloc_matr_simpla(d_c + 1, d_l + 1);

		for (int i = 0; i <= d_l; i++)
			for (int j = 0; j <= d_c; j++)
				copie_mat[d_c - j][i] = (*mat)[x1 + i][y1 + j];

		if (selectie == 0) {
			elib_matr(mat, *linii);
			*mat = copie_mat;
			*linii = d_c + 1;
			*coloane = d_l + 1;
		} else {
			for (int i = 0; i <= d_l; i++)
				for (int j = 0; j <= d_c; j++)
					(*mat)[x1 + i][y1 + j] = copie_mat[i][j];

			elib_matr(&copie_mat, d_c + 1);
		}

	} else {
		copie_mat = aloc_matr_simpla(d_c + 1, (d_l + 1) * 3);

		for (int i = 0; i <= d_l; i++) {
			for (int c = 0; c <= d_c; c++)
				for (int k = 0; k <= 2; k++)
					copie_mat[d_c - c][i * 3 + k] = (*mat)[x1 + i][y1 * 3 + c * 3 + k];
		}

		if (selectie == 0) {
			elib_matr(mat, *linii);
			*mat = copie_mat;
			*linii = d_c + 1;
			*coloane = (d_l + 1) * 3;
		} else {
			for (int i = 0; i <= d_l; i++)
				for (int j = 0; j < (d_c + 1) * 3; j++)
					(*mat)[x1 + i][y1 * 3 + j] = copie_mat[i][j];

			elib_matr(&copie_mat, d_c + 1);
		}
	}
}

void reselectare(int *x1, int *y1, int *x2, int *y2, int linii, int coloane,
				 short int *selectie, int color)
{
	*x1 = 0; *y1 = 0;
	*x2 = linii - 1;
	if (color)
		*y2 = coloane / 3 - 1;
	else
		*y2 = coloane - 1;

	*selectie = 0;
}
