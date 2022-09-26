// Stroe Teodora - 311CA

#include <stdio.h>
#include <stdlib.h>

FILE *f;

int read_input_hexa(int n, int **v, unsigned int ***imag)
{
	*v = (int *)calloc(n, sizeof(int));
	if (*v == NULL) {
		fprintf(stderr, "calloc() failed\n");
		return -1;
	}
	*imag = (unsigned int **)malloc(n * sizeof(unsigned int *));
	if (*imag == NULL) {
		fprintf(stderr, "malloc() failed\n");
		return -1;
	}
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d", (*v) + i);
		(*imag)[i] = (unsigned int *)calloc((*v)[i], sizeof(unsigned int ));
		if ((*imag)[i] == NULL) {
			fprintf(stderr, "calloc() failed\n");
			return -1;
		}
		for (int j = 0; j < (*v)[i]; j++) {
            fscanf(f, "%X", &((*imag)[i][j]));
		}
	}
	return 0;
}

int modif(unsigned int ***imag, char dim_date, int linie, int index_date,\
unsigned int val_noua, int **v)
{
	if (dim_date == 'C') {
		if ((long unsigned int)index_date > (*v)[linie] * sizeof(unsigned int)) {
            int o = index_date / sizeof(unsigned int);
            if ((index_date % 4) != 0) {
                o += 1;
            }
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
			(*v)[linie] = o;
			*pointer = val_noua;
		} else {
            char *pointer = (char *)((*imag)[linie]);
			pointer += index_date - 1;
			*pointer = val_noua;
		}
	} else if (dim_date == 'S') {
		if ((long unsigned int)index_date * 2 > (*v)[linie] * sizeof(unsigned int)) {
            int o = (index_date * 2) / sizeof(unsigned int) + (index_date % 2);
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
			(*v)[linie] = o;
			*pointer = val_noua;
		} else {
            short int *pointer = (short int *)((*imag)[linie]);
			pointer += index_date - 1;
			*pointer = val_noua;
		}
	} else {
		if (index_date > (*v)[linie]) {
            int o = index_date;
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
			(*v)[linie] = o;
			*pointer = val_noua;
		} else {
            int *pointer = (int *)((*imag)[linie]);
			pointer += index_date - 1;
			*pointer = val_noua;
		}
	}
	return 0;
}

    void conversie(unsigned int x, int nr_cifre)
    {
        char cifre_hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',\
        'A', 'B', 'C', 'D', 'E', 'F'};
        if(nr_cifre < 8)
        {
            conversie(x / 16, nr_cifre + 1);
            printf("%c",cifre_hexa[x % 16]);
        }
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
        char *p = (char *)(*imag)[linie];
        p += 2 * index_date;
        char *q;
        q = p + 1;
        char aux;
        aux = *p;
        *p = *q;
        *q = aux;
    } else if (dim_date == 'I'){
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

void matrice_noua(int **imag, int n, int *v, int ***m_depl)
{
    *m_depl = (int **)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        (*m_depl)[i] = (int *)malloc(sizeof(unsigned int) * v[i]);
        for (int j = 0; j < v[i]; j++)
        {
            char *g = (char *)&((imag)[i][j]);
            (*m_depl)[i][sizeof(unsigned int) * j] = !(!(*g));
            g++;
            (*m_depl)[i][sizeof(unsigned int) * j + 1] = !(!(*g));
            g++;
            (*m_depl)[i][sizeof(unsigned int) * j + 2] = !(!(*g));
            g++;
            (*m_depl)[i][sizeof(unsigned int) * j + 3] = !(!(*g));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4 * v[i]; j++) {
            printf("%d ", (*m_depl)[i][j]);
        }
        printf("\n");
    }
}


void print_modifs(int n, int *v, unsigned int **imag) {
	for (int i = 0; i < n; i++) {
		int *p_i = (int *)&imag[i][0];
		for (int j = 0; j < v[i]; j++) {
            conversie(*(p_i + j), 0);
            printf(" ");
		}
		printf("\n");
	}
}
