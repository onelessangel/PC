// Stroe Teodora - 311CA

#include <stdio.h>
#include "bubble_sort.h"
#include "crescator.h"
#include "descrescator.h"

#define LUNGIME 100

int main(void)
{
	int n, x, v[LUNGIME];
	scanf("%d", &n);
	x = n;
	// se realizeaza prima scadere
	x = descrescator(x) - crescator(x);
	short int l = 0;
	// se memoreaza fiecare diferenta in vectorul 'v'
	v[l] = x;
	short int gasit = -1;
	// se realizeaza scaderi pana cand secventa cautata incepe sa se repete
	while (gasit == -1) {
		x = descrescator(x) - crescator(x);
		l++;
		v[l] = x;
		for (int i = 0; i < l; i++) {
			if (v[i] == x) {
				gasit = i;
				break;
			}
		}
	}

	printf("%hd\n", gasit);
	for (int i = gasit; i < l; i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}
