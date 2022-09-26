#include <stdio.h>

#define NMAX 9

void bubble_sort(short int n, short int v[NMAX])
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				int copie = v[j];
				v[j] = v[j + 1];
				v[j + 1] = copie;
			}
		}
	}
}
