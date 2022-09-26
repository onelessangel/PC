#include "alocari.h"

short int selectare(char input[MAX_LUNG], int *x1, int *y1, int *x2, int *y2,
					int linii, int coloane, unsigned char cifra)
{
	char *comanda, *arg1, *arg2, *arg3, *arg4;
	char cifre[] = "-1234567890";
	int col_1, lin_1, col_2, lin_2;
	int minim_x, minim_y, maxim_x, maxim_y;
	if (cifra == '3' || cifra == '6')
		coloane /= 3;
	comanda = strtok(input, " ");
	arg1 = strtok(NULL, " ");
	if (!arg1)
		return 2;
	if (strspn(arg1, cifre) == strlen(arg1)) {
		arg2 = strtok(NULL, " ");
		if (!arg2)
			return 2;
		if (strspn(arg2, cifre) == strlen(arg2)) {
			arg3 = strtok(NULL, " ");
			if (!arg3)
				return 2;
			if (strspn(arg3, cifre) == strlen(arg3)) {
				arg4 = strtok(NULL, " ");
				if (!arg4)
					return 2;
				if (strspn(arg4, cifre) != strlen(arg4))
					return 2;
			} else {
				return 2;
			}
		} else {
			return 2;
		}
	} else {
		if (strcmp(arg1, "ALL") == 0) {
			*x1 = 0; *y1 = 0;
			*x2 = linii - 1; *y2 = coloane - 1;
			printf("Selected ALL\n");
			return 0;
		} else {
			return 2;
		}
	}
	col_1 = atoi(arg1); lin_1 = atoi(arg2);
	col_2 = atoi(arg3); lin_2 = atoi(arg4);

	minim_x = min(lin_1, lin_2); minim_y = min(col_1, col_2);
	maxim_x = max(lin_1, lin_2); maxim_y = max(col_1, col_2);
	if (minim_x < 0 || minim_x > linii - 1 ||  maxim_x > linii) {
		printf("Invalid set of coordinates\n");
		return 3;
	}
	if (minim_x == maxim_x || minim_y == maxim_y) {
		printf("Invalid set of coordinates\n");
		return 3;
	}
	if (minim_y < 0 || minim_y > coloane - 1 || maxim_y > coloane) {
		printf("Invalid set of coordinates\n");
		return 3;
	}
	printf("Selected %d %d %d %d\n", minim_y, minim_x, maxim_y, maxim_x);
	*x1 = minim_x; *y1 = minim_y;
	*x2 = maxim_x - 1; *y2 = maxim_y - 1;
	if (*x1 == 0 && *y1 == 0 && *x2 == linii - 1 && *y2 == coloane - 1)
		return 0;
	else
		return 1;
}
