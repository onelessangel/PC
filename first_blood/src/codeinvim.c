// Stroe Teodora - 311CA

#include <stdio.h>
#include "bubble_sort_2.h"

#define MAXIMUM 100

int main(void)
{
	int n, m, p_min, a[2][MAXIMUM];
	short int solutie = 0, posibilitate_crestere = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[0][i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[1][i]);
	scanf("%d", &p_min);

	int med_act = 0; // medie actuala
	int crestere_posibila[MAXIMUM], k = 0;
	// se calculeaza media actuala si cresterile posibile, in functie de materie
	for (int i = 0; i < n; i++) {
		med_act += a[0][i] * a[1][i];
		if (a[0][i] != 10) {
			// exista cel putin o nota diferita de 10
			// se poate face cel putin o crestere a mediei actuale
			posibilitate_crestere = 1;
			crestere_posibila[k] = a[1][i] * (10 - a[0][i]);
			k++;
		}
	}

	// toate notele sunt de 10, deci Mihai nu isi poate creste media
	if (posibilitate_crestere == 0) {
		printf("-1\n");
	} else {
		// se sorteaza crescator vectorul cu posibilele cresteri
		bubble_sort_2(k, crestere_posibila);
		m = 0;
		solutie = 0;

		// se adauga treptat cresterile posibile la media actuala
		while (crestere_posibila[0] != 0) {
			med_act += crestere_posibila[k - 1];
			crestere_posibila[k - 1] = 0;
			k--;
			m++;
			if (med_act >= p_min) {
				solutie = 1;
				break;
			}
		}
		if (solutie == 1)
			printf("%d\n", m);
		else
			printf("-1\n");
	}
	return 0;
}
