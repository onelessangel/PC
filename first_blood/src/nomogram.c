// Stroe Teodora - 311CA

#include <stdio.h>
#include "read_matrix.h"
#include "verif_rows.h"
#include "verif_cols.h"

#define NMAX 100

int main(void)
{
	int n, m, t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d%d", &n, &m);
		int linii[NMAX][NMAX], coloane[NMAX][NMAX];
		for (int i = 0; i < n; i++) {
			scanf("%d", &linii[i][0]);
			for (int j = 1; j <= linii[i][0]; j++)
				scanf("%d", &linii[i][j]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &coloane[i][0]);
			for (int j = 1; j <= coloane[i][0]; j++)
				scanf("%d", &coloane[i][j]);
		}
		int a[NMAX][NMAX];
		read_matrix(n, m, a);

		short int ok = 1;
		ok = verif_rows(n, m, a, linii);

		if (ok == 0) {
			printf("Eroare\n");
		} else {
			ok = verif_cols(n, m, a, coloane);
			if (ok == 0)
				printf("Eroare\n");
			else
				printf("Corect\n");
		}
	}
	return 0;
}
