#include <stdio.h>

#define NMAX 9

int descrescator(int n)
{
	short int nr_cifre = 0, v[NMAX];
	// se formeaza un vector care contine cifrele nr. n
	while (n != 0) {
		nr_cifre++;
		v[nr_cifre - 1] = n % 10;
		n /= 10;
	}
	// se sorteaza crescator vectorul
	bubble_sort(nr_cifre, v);
	// se formeaza numarul format din cifrele lui n, dar ordonate descrescator
	int nr_descrescator = 0;
	for (int i = nr_cifre - 1; i >= 0; i--)
		nr_descrescator = nr_descrescator * 10 + v[i];
	return nr_descrescator;
}
