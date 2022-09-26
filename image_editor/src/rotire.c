#include "alocari.h"

int rotire(char input[MAX_LUNG], short int *selectie, int *x1, int *y1,
		   int *x2, int *y2, unsigned char ***mat, int *linii, int *coloane,
		   unsigned char cifra)
{
	int unghi = 0;
	short int semn;
	int color;
	char *comanda, *rest;
	char cifre[] = "1234567890";

	comanda = strtok(input, " ");
	rest = strtok(NULL, " ");
	if (!rest) {
		printf("Invalid command\n");
		return 0;
	}

	if (rest[0] == '-' && strspn(rest + 1, cifre) == strlen(rest + 1)) {
		semn = -1;
		unghi = atoi(rest + 1);
	} else {
		if (strspn(rest, cifre) == strlen(rest)) {
			semn = 1;
			unghi = atoi(rest);
		}
	}

	if (unghi % 90 != 0 || unghi > 360) {
		printf("Unsupported rotation angle\n");
		return 0;
	}
	if (*selectie == 1) {
		if (*x2 - *x1 != *y2 - *y1) {
			printf("The selection must be square\n");
			return 0;
		}
	}
	if (semn == 1)
		printf("Rotated %d\n", unghi);
	else
		printf("Rotated -%d\n", unghi);
	if (unghi == 0 || unghi == 360)
		return 0;

	if (cifra != '3' && cifra != '6')
		color = 0;
	else
		color = 1;

	unsigned char **copie_mat;

	int d_l = *x2 - *x1;
	int d_c = *y2 - *y1;

	if (unghi == 90 && semn == 1 || unghi == 270 && semn == -1) {
		r_90(color, mat, *selectie, d_c, d_l, *x1, *y1, *x2, *y2, linii,
			 coloane);
	} else if (unghi == 180) {
		r_180(color, mat, *selectie, d_c, d_l, *x1, *y1, *x2, *y2, linii,
			  coloane);
	} else if (unghi == 270 && semn == 1 || unghi == 90 && semn == -1) {
		r_270(color, mat, *selectie, d_c, d_l, *x1, *y1, *x2, *y2, linii,
			  coloane);
	}

	if (*selectie == 0)
		reselectare(x1, y1, x2, y2, *linii, *coloane, selectie, color);
}
