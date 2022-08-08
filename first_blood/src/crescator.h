#include <stdio.h>

#define NMAX 9

int crescator(int n)
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
	// se formeaza numarul format din cifrele lui n, dar ordonate crescator
	int nr_crescator = 0;
	for (short int i = 0; i < nr_cifre; i++)
		nr_crescator = nr_crescator * 10 + v[i];
	return nr_crescator;
}
