#include <stdio.h>

#define NMAX 100

void read_matrix(int n, int m, int a[NMAX][NMAX])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
}
