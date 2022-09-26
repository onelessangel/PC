// Stroe Teodora - 311CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "read_input.h"

int main()
{
    f = fopen("date.in", "r");
	int n;
	fscanf(f, "%d", &n);
	int *v;
	unsigned int **imag;
	// se citeste dinamic harta
	read_input_hexa(n, &v, &imag);
	signed char *p = NULL;
	int numaratoare = 0;
	long long suma = 0;
	// se numara si se adauga la suma bytes-ii de pe prima linie
	for (int j = 0; j < v[0]; j++) {
		p = (signed char *)&imag[0][j];
		for (int k = 0; k < 4; k++) {
			suma += *(p + k);
			numaratoare++;
		}
	}
	if (n != 1) {
		// se numara si se adauga la suma bytes-ii de pe ulima linie
		for (int j = 0; j < v[n - 1]; j++) {
			p = (signed char *)&imag[n - 1][j];
			for (int k = 0; k < 4; k++) {
				suma += *(p + k);
				numaratoare++;
			}
		}
		// se numara si se adauga la suma primul si ultimul byte de pe linie
		for (int i = 1; i < n - 1; i++) {
			p = (signed char *)&imag[i][0];
 			suma += *p;
			numaratoare++;
 			p = (signed char *)&imag[i][v[i] - 1];
 			p += 3;
 			suma += *p;
 			numaratoare++;
		}
	}
	// se calculeaza media aritmetica
	double m_a = (double)suma / numaratoare;
	printf("task 1\n");
	printf("%.8lf\n", m_a);

	int k;
	fscanf(f, "%d", &k);

	char op, dim_date;
	int  linie, index_date;
	unsigned int val_noua;
	for (int i = 0; i < k; i ++) {
		fscanf(f, " %c %c%d%d", &op, &dim_date, &linie, &index_date);
		if (op == 'M') {
			fscanf(f, "%X", &val_noua);
			modif(&imag, dim_date, linie, index_date, val_noua, &v);
		} else if (op == 'D') {
            del(&imag, dim_date, linie, index_date);
		} else if (op == 'S') {
            schimb(&imag, dim_date, linie, index_date);
		}
	}
	print_modifs(n, v, imag);

	// int **m_depl;
	// matrice_noua(imag, n, v, &m_depl);
	return 0;
}
