// Stroe Teodora - 311CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int modif(unsigned int ***imag, char dim_date, int linie, int index_date,\
unsigned int val_noua, int **v)
{
	if (dim_date == 'C') {
		// se verifica daca portiunea de date ce trebuie modificata se afla in
		// afara hartii actuale
		if ((long unsigned int)index_date > (*v)[linie] * sizeof(unsigned int)) {
			int o = index_date / sizeof(unsigned int);
			if ((index_date % 4) != 0) {
				o += 1;
			}
			// se realoca memorie si portiunea cuprinsa intre ultima valoare
			// a hartii si portiunea modificata este completata cu zerouri
			unsigned int *a = (unsigned int *)calloc(o, sizeof(unsigned int));
			if (a == NULL) {
				fprintf(stderr, "calloc() failed\n");
				return -1;
			} else {
				memmove(a, (*imag)[linie], (*v)[linie] * sizeof(unsigned int));
				free((*imag)[linie]);
				(*imag)[linie] = a;
			}
			char *pointer = (char *)((*imag)[linie]);
			pointer += index_date - 1;
			// se creste lungimea liniei hartii
			(*v)[linie] = o;
			// prin intermediul unui pointer, se modifica elementul cerut
			*pointer = val_noua;
		} else {
			// in caz contrar, se modifica elementul cerut cu ajutorul unui
			// pointer
			char *pointer = (char *)((*imag)[linie]);
			pointer += index_date - 1;
			*pointer = val_noua;
		}
	} else if (dim_date == 'S') {
		// se verifica daca portiunea de date ce trebuie modificata se afla in
		// afara hartii actuale
		if ((long unsigned int)index_date * 2 > (*v)[linie] * sizeof(unsigned int)) {
			int o = (index_date * 2) / sizeof(unsigned int) + (index_date % 2);
			// se realoca memorie si portiunea cuprinsa intre ultima valoare
			// a hartii si portiunea modificata este completata cu zerouri
			unsigned int *a = (unsigned int *)calloc(o, sizeof(unsigned int));
			if (a == NULL) {
				fprintf(stderr, "calloc() failed\n");
				return -1;
			} else {
				memmove(a, (*imag)[linie], (*v)[linie] * sizeof(unsigned int));
				free((*imag)[linie]);
				(*imag)[linie] = a;
			}
			short int *pointer = (short int *)((*imag)[linie]);
			pointer += index_date - 1;
			// se creste lungimea liniei hartii
			(*v)[linie] = o;
			// prin intermediul unui pointer, se modifica elementul cerut
			*pointer = val_noua;
		} else {
			// in caz contrar, se modifica elementul cerut cu ajutorul unui
			// pointer
			short int *pointer = (short int *)((*imag)[linie]);
			pointer += index_date - 1;
			*pointer = val_noua;
		}
	} else {
		// se verifica daca portiunea de date ce trebuie modificata se afla in
		// afara hartii actuale
		if (index_date > (*v)[linie]) {
			int o = index_date;
			// se realoca memorie si portiunea cuprinsa intre ultima valoare
			// a hartii si portiunea modificata este completata cu zerouri
			unsigned int *a = (unsigned int *)calloc(o, sizeof(unsigned int));
			if (a == NULL) {
				fprintf(stderr, "calloc() failed\n");
				return -1;
			} else {
				memmove(a, (*imag)[linie], (*v)[linie] * sizeof(unsigned int));
				free((*imag)[linie]);
				(*imag)[linie] = a;
			}
			int *pointer = (int *)((*imag)[linie]);
			pointer += index_date - 1;
			// se creste lungimea liniei hartii
			(*v)[linie] = o;
			// prin intermediul unui pointer, se modifica elementul cerut
			*pointer = val_noua;
		} else {
			// in caz contrar, se modifica elementul cerut cu ajutorul unui
			// pointer
			int *pointer = (int *)((*imag)[linie]);
			pointer += index_date - 1;
			*pointer = val_noua;
		}
	}
	return 0;
}

void del(unsigned int ***imag, char dim_date, int linie, int index_date) {
	if (dim_date == 'C') {
		char *p = (char *)(*imag)[linie];
		*(p + index_date - 1) = 0;
	} else if (dim_date == 'S') {
		short int *p = (short int *)(*imag)[linie];
		*(p + index_date - 1) = 0;
	} else {
		int *p = (int *)(*imag)[linie];
		*(p + index_date - 1) = 0;
	}
}

void schimb(unsigned int ***imag, char dim_date, int linie, int index_date) {
	if (dim_date == 'S') {
		// daca dimensiunea datelor este de 2 bytes se interschimba valorile
		// celor 2 bytes din blocul de memorie specificat
		char *p = (char *)(*imag)[linie];
		p += 2 * index_date;
		char *q;
		q = p + 1;
		char aux;
		aux = *p;
		*p = *q;
		*q = aux;
	} else if (dim_date == 'I'){
		// daca dimensiunea datelor este de 4 bytes
		// se interschimba valorile bytes-ilor extremi
		// si a celor interni din blocul de memorie specificat
		char *p = (char *)&(*imag)[linie][index_date];
		char *q;
		q = p + 3;
		char aux;
		aux = *p;
		*p = *q;
		*q = aux;
		p += 1;
		q -= 1;
		aux = *p;
		*p = *q;
		*q = aux;
	}
}
