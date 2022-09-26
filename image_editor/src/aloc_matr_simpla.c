#include "alocari.h"

unsigned char **aloc_matr_simpla(int linii, int coloane)
{
	unsigned char **mat;
	mat = (unsigned char **)malloc(linii * sizeof(unsigned char *));
	int copie_i;

	if (!mat) {
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}

	for (int i = 0; i < linii; i++) {
		mat[i] = (unsigned char *)calloc(coloane, sizeof(unsigned char));

		if (!mat[i]) {
			fprintf(stderr, "calloc() failed\n");
			copie_i = i;
			while (copie_i >= 0) {
				free(mat[copie_i]);
				copie_i--;
			}
			free(mat);
			return NULL;
		}
	}
	return mat;
}

void elib_matr(unsigned char ***mat, int linii)
{
	for (int i = 0; i < linii; i++)
		free((*mat)[i]);
	free((*mat));
	*mat = NULL;
}

void afisare_matr(unsigned char **mat, int coloane, int linii)
{
	for (int i = 0; i < linii; i++) {
		for (int j = 0; j < coloane; j++)
			printf("%hd ", mat[i][j]);
		printf("\n");
	}
}
