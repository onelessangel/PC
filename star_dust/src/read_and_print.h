// Stroe Teodora - 311CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		scanf("%d", (*v) + i);
		(*imag)[i] = (unsigned int *)calloc((*v)[i], sizeof(unsigned int ));
		if ((*imag)[i] == NULL) {
			fprintf(stderr, "calloc() failed\n");
			return -1;
		}
		for (int j = 0; j < (*v)[i]; j++) {
			scanf("%X", &((*imag)[i][j]));
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
