#include <stdio.h>

#define NMAX 100

short int verif_cols(int n, int m, int a[NMAX][NMAX], int coloane[NMAX][NMAX])
{
	short int ok = 1;
	for (int j = 0; j < m; j++) {
		int contor = 0, secventa = 0, gasit_unu = 0, i;
		for (i = 0; i < n - 1; i++) {
			if (a[i][j] == 1) {
				secventa++;
				gasit_unu = 1;
			} else if (a[i][j] == 0 && gasit_unu == 1) {
				contor++;
				if (contor > coloane[j][0]) {
					ok = 0;
				} else {
					if (secventa != coloane[j][contor])
						ok = 0;
				}
				secventa = 0;
				gasit_unu = 0;
			}
		}
		if (a[i][j] == 1) {
			secventa++;
			contor++;
			if (contor > coloane[j][0]) {
				ok = 0;
			} else {
				if (secventa != coloane[j][contor])
					ok = 0;
			}
		}
	}
	return ok;
}
