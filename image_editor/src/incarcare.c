#include "alocari.h"

void incarcare(char input[MAX_LUNG], unsigned char *cifra, int *linii,
			   int *coloane, short int *max_intensitate,
			   short int *exista_fisier, int *x1, int *y1, int *x2, int *y2,
			   unsigned char ***mat)
{
	FILE *bin, *text;
	char *fisier, *comanda;
	long cursor;
	comanda = strtok(input, " ");
	fisier = strtok(NULL, " ");

	if (*mat) {
		elib_matr(mat, *linii);
		*mat = NULL;
	}
	if (fisier) {
		bin = fopen(fisier, "rb");
		text = fopen(fisier, "r");

		if (text && bin) {
			printf("Loaded %s\n", fisier);
			*exista_fisier = 1;

			antet(text, cifra, coloane, linii, max_intensitate);

			*x1 = 0; *y1 = 0;
			*x2 = *linii - 1; *y2 = *coloane - 1;

			if (*cifra == '3' || *cifra == '6')
				*coloane = 3 * *coloane;

			if (*cifra == '1' || *cifra == '2' || *cifra == '3') {
				*mat = matrice(text, *cifra, *coloane, *linii);
			} else {
				cursor = ftell(text);
				fseek(bin, cursor, SEEK_SET);
				*mat = matrice(bin, *cifra, *coloane, *linii);
			}
			fclose(text);
			fclose(bin);
		} else {
			printf("Failed to load %s\n", fisier);
			*exista_fisier = 0;
		}
	} else {
		printf("Invalid command\n");
		*exista_fisier = 0;
	}
}

unsigned char **matrice(FILE *fisier, unsigned char cifra, int coloane,
						int linii)
{
	unsigned char **mat;

	mat = aloc_matr_simpla(linii, coloane);

	if (cifra == '1' || cifra == '2' || cifra == '3') {
		short int element;
		for (int i = 0; i < linii; i++) {
			for (int j = 0; j < coloane; j++) {
				fscanf(fisier, "%hd", &element);
				mat[i][j] = (unsigned char)element;
			}
		}

	} else {
		unsigned char element;
		for (int i = 0; i < linii; i++) {
			for (int j = 0; j < coloane; j++) {
				fread(&element, sizeof(unsigned char), 1, fisier);
				mat[i][j] = element;
			}
		}
	}
	return mat;
}
