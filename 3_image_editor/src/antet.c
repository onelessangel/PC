#include "alocari.h"

void antet(FILE *text, unsigned char *cifra, int *coloane, int *linii,
		   short int *max_intensitate)
{
	unsigned char P;
	o_fi_comentariu_ascii(text);

	fscanf(text, "%c", &P);

	// *******
	// printf("ftell = %ld\n", ftell(text));

	fscanf(text, "%c ", cifra);

	// *******
	// printf("ftell = %ld\n", ftell(text));

	o_fi_comentariu_ascii(text);

	fscanf(text, "%d%d ", coloane, linii);

	//*******
	// printf("...%d %d...\n", *coloane, *linii);

	// *******
	// printf("ftell = %ld\n", ftell(text));

	o_fi_comentariu_ascii(text);

	if (*cifra != '1' && *cifra != '4') {
		fscanf(text, "%hd ", max_intensitate);

		// *******
		// printf("ftell = %ld\n", ftell(text));

		o_fi_comentariu_ascii(text);
	}
}

void o_fi_comentariu_ascii(FILE *text)
{
	char comentariu[MAX_LUNG];
	unsigned char car_urm;

	fscanf(text, "%c", &car_urm);
	while (car_urm == '#') {
		fgets(comentariu, MAX_LUNG, text);
		fscanf(text, "%c", &car_urm);
	}
	fseek(text, -1, SEEK_CUR);
}
