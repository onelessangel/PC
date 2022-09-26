#include "alocari.h"

int main(void)
{
	char *comanda, copie[MAX_LUNG], input[MAX_LUNG];
	unsigned char cifra, **mat = NULL;
	int linii, coloane, x1, y1, x2, y2;
	short int exista_fisier = 0, max_intensitate, selectie = 0, rezultat;
	fgets(input, MAX_LUNG, stdin); input[strlen(input) - 1] = 0;
	strcpy(copie, input); comanda = strtok(input, " ");
	while (comanda) {
		if (strcmp(comanda, "EXIT") == 0) {
			*comanda = 0; comanda = NULL;
			terminare(exista_fisier, linii, &mat);
		} else {
			if (strcmp(comanda, "LOAD") == 0) {
				incarcare(copie, &cifra, &linii, &coloane, &max_intensitate,
						  &exista_fisier, &x1, &y1, &x2, &y2, &mat);
				selectie = 0;
			} else if (strcmp(comanda, "SELECT") == 0) {
				if (exista_fisier) {
					int retur  = selectare(copie, &x1, &y1, &x2, &y2, linii,
										   coloane, cifra);
					if (retur == 1 || retur == 0)
						selectie = retur;
					else if (retur == 2)
						printf("Invalid command\n");
				} else {
					printf("No image loaded\n"); selectie = 0;
				}
			} else if (strcmp(comanda, "ROTATE") == 0) {
				if (exista_fisier) {
					rotire(copie, &selectie, &x1, &y1, &x2, &y2, &mat, &linii,
						   &coloane, cifra);
				} else {
					printf("No image loaded\n");
				}
			} else if (strcmp(comanda, "CROP") == 0) {
				if (exista_fisier) {
					printf("Image cropped\n");
					taiere(&selectie, &x1, &y1, &x2, &y2, &mat, &linii,
						   &coloane, cifra);
				} else {
					printf("No image loaded\n");
				}
			} else if (strcmp(comanda, "GRAYSCALE") == 0) {
				if (exista_fisier) {
					if (cifra == '3' || cifra == '6') {
						printf("Grayscale filter applied\n");
						printre_tonuri_cenusii(&mat, x1, y1, x2, y2);
					} else {
						printf("Grayscale filter not available\n");
					}
				} else {
					printf("No image loaded\n");
				}
			} else if (strcmp(comanda, "SEPIA") == 0) {
				if (exista_fisier) {
					if (cifra == '3' || cifra == '6') {
						printf("Sepia filter applied\n");
						sepia(&mat, x1, y1, x2, y2, max_intensitate);
					} else {
						printf("Sepia filter not available\n");
					}
				} else {
					printf("No image loaded\n");
				}
			} else if (strcmp(comanda, "SAVE") == 0) {
				if (exista_fisier)
					salvare(copie, mat, linii, coloane, cifra, max_intensitate);
				else
					printf("No image loaded\n");
			} else {
				printf("Invalid command\n");
			}
			if (fgets(input, MAX_LUNG, stdin)) {
				if (input[strlen(input) - 1] == '\n') {
					input[strlen(input) - 1] = 0;
					strcpy(copie, input); comanda = strtok(input, " ");
				}
			} else {
				*comanda = 0; comanda = NULL;
			}
		}
	}
	return 0;
}
