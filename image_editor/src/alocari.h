#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FISIER 50
#define MAX_LUNG 100

void terminare(short int exista_fisier, int linii, unsigned char ***mat);

void antet(FILE *text, unsigned char *cifra, int *coloane, int *linii,
		   short int *max_intensitate);

unsigned char **aloc_matr_simpla(int linii, int coloane);

void incarcare(char input[MAX_LUNG], unsigned char *cifra, int *linii,
			   int *coloane, short int *max_intensitate,
			   short int *exista_fisier, int *x1, int *y1, int *x2, int *y2,
			   unsigned char ***mat);

unsigned char **matrice(FILE *fisier, unsigned char cifra, int coloane,
						int linii);

void elib_matr(unsigned char ***mat, int linii);

short int selectare(char input[MAX_LUNG], int *x1, int *y1, int *x2, int *y2,
					int linii, int coloane, unsigned char cifra);

int rotire(char input[MAX_LUNG], short int *selectie, int *x1, int *y1,
		   int *x2, int *y2, unsigned char ***mat, int *linii, int *coloane,
		   unsigned char cifra);

void r_90(int color, unsigned char ***mat, short int selectie, int d_c,
		  int d_l, int x1, int y1, int x2, int y2, int *linii, int *coloane);

void r_180(int color, unsigned char ***mat, short int selectie, int d_c,
		   int d_l, int x1, int y1, int x2, int y2, int *linii, int *coloane);

void r_270(int color, unsigned char ***mat, short int selectie, int d_c,
		   int d_l, int x1, int y1, int x2, int y2, int *linii, int *coloane);

void finalizare_rotire(short int selectie, unsigned char ***mat, int *linii,
					   int *coloane, int lin_nou, int col_nou,
					   unsigned char ***copie_mat, int color, int d_l,
					   int d_c, int x1, int y1);

void reselectare(int *x1, int *y1, int *x2, int *y2, int linii, int coloane,
				 short int *selectie, int color);

int taiere(short int *selectie, int *x1, int *y1, int *x2, int *y2,
		   unsigned char ***mat, int *linii, int *coloane,
		   unsigned char cifra);

void printre_tonuri_cenusii(unsigned char ***mat, int x1, int y1, int x2,
							int y2);

void sepia(unsigned char ***mat, int x1, int y1, int x2, int y2,
		   short int max_intensitate);

int salvare(char input[MAX_LUNG], unsigned char **mat, int linii, int coloane,
			unsigned char cifra, short int max_intensitate);

void o_fi_comentariu_ascii(FILE *text);

int min(int x, int y);

int max(int x, int y);

void schimbare_culoare(unsigned char *x, double n, short int max_intensitate);

void afisare_matr(unsigned char **mat, int coloane, int linii);

void salvare_matr(unsigned char **mat, int coloane, int linii, FILE *fisier,
				  int ascii);
