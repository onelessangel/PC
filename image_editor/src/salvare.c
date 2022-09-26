#include "alocari.h"

int salvare(char input[MAX_LUNG], unsigned char **mat, int linii, int coloane,
			unsigned char cifra, short int max_intensitate)
{
	FILE *fisier;
	char transformare[2][7] = {{'0', '4', '5', '6', '4', '5', '6'}, {'0', '1', '2', '3', '1', '2', '3'}};
	char *comanda, *format, *nume_fisier;
	int ascii = 0;
	int i = 0;

	comanda = strtok(input, " ");
	nume_fisier = strtok(NULL, " ");
	if (!nume_fisier) {
		printf("Invalid command\n");
		return 0;
	}

	format = strtok(NULL, " ");
	if (!format)
		ascii = 0;
	else
		if (strcmp(format, "ascii") == 0)
			ascii = 1;

	printf("Saved %s\n", nume_fisier);

	fisier = fopen(nume_fisier, "w+");

	fprintf(fisier, "P%c\n", transformare[(int)ascii][(int)cifra - '0']);

	if (cifra == '3' || cifra == '6')
		fprintf(fisier, "%d %d\n", coloane / 3, linii);
	else
		fprintf(fisier, "%d %d\n", coloane, linii);
	if (cifra != '1' && cifra != '4')
		fprintf(fisier, "%hd\n", max_intensitate);

	if (ascii == 1) {
		salvare_matr(mat, coloane, linii, fisier, ascii);

		fclose(fisier);
	} else {
		fclose(fisier);
		fisier = fopen(nume_fisier, "ab");
		salvare_matr(mat, coloane, linii, fisier, ascii);
		fclose(fisier);
	}
}

void salvare_matr(unsigned char **mat, int coloane, int linii, FILE *fisier,
				  int ascii)
{
	if (ascii == 1) {
		for (int i = 0; i < linii; i++) {
			for (int j = 0; j < coloane; j++)
				fprintf(fisier, "%hd ", mat[i][j]);
			fprintf(fisier, "\n");
		}
	} else {
		for (int i = 0; i < linii; i++)
			for (int j = 0; j < coloane; j++)
				fwrite(&mat[i][j], sizeof(unsigned char), 1, fisier);
	}
}
