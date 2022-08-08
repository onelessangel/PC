#include <stdio.h>

#define NMAX 100

short int verif_rows(int n, int m, int a[NMAX][NMAX], int linii[NMAX][NMAX])
{
	short int ok = 1;
	for (int i = 0; i < n; i++) {
		int contor = 0, secventa = 0, gasit_unu = 0, j;
		for (j = 0; j < m - 1; j++) {
			if (a[i][j] == 1) {
				secventa++;
				gasit_unu = 1;
			} else if (a[i][j] == 0 && gasit_unu == 1) {
				contor++;
				if (contor > linii[i][0]) {
					ok = 0;
				} else {
					if (secventa != linii[i][contor])
						ok = 0;
				}
				secventa = 0;
				gasit_unu = 0;
			}
		}
		if (a[i][j] == 1) {
			secventa++;
			contor++;
			if (contor > linii[i][0]) {
				ok = 0;
			} else {
				if (secventa != linii[i][contor])
					ok = 0;
			}
		}
	}
	return ok;
}
