// Stroe Teodora - 311CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 9

int read_input(int n, int **v, char ****imag)
{
	*v = (int *)calloc(n, sizeof(int));
	if (*v == NULL) {
		fprintf(stderr, "calloc() failed\n");
		return -1;
	}
	*imag = (char ***)malloc(n * sizeof(char**));
	if (*imag == NULL) {
		fprintf(stderr, "malloc() failed\n");
		return -1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", (*v) + i);
		(*imag)[i] = (char **)calloc(n, sizeof(char *));
		if ((*imag)[i] == NULL) {
			fprintf(stderr, "calloc() failed\n");
			return -1;
		}
		for (int j = 0; j < (*v)[i]; j++) {
			char str[NMAX];
			scanf("%s", str);
			(*imag)[i][j] = (char *)malloc(NMAX - 1);
			if ((*imag)[i][j] == NULL) {
				fprintf(stderr, "malloc() failed\n");
				return -1;
			}
			memmove((*imag)[i][j], str, NMAX - 1);
		}
	}
	return 0;
}