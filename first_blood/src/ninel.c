// Stroe Teodora - 311CA

#include <stdio.h>
#include "max.h"
#include "min.h"

#define MINIM 1000000
#define MAXIM 0

int main(void)
{
	int n, a, b, c;
	int special = 0, xmax_impar = MAXIM, xmin_par = MINIM;
	long S = 0;
	double m_a;
	// determina daca exista sau nu copaci 'speciali' pe pozitii pare/impare
	int gasit_special_par = 0, gasit_special_impar = 0, destui_copaci = 0;
	scanf("%d", &n);
	// cazul cu 1 sau 2 copaci
	if (n <= 2) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a);
		destui_copaci = 0;
		special = 0;
		gasit_special_impar = 0;
		gasit_special_par = 0;
	} else {
		// cazul cu 3 copaci
		scanf("%d%d%d", &a, &b, &c);
		destui_copaci = 1;
		if (a < b && b > c) {
			special++;
			S += b;
			xmax_impar = b;
			gasit_special_impar = 1;
		}
		a = b;
		b = c;
		// cazul cu mai mult de 3 copaci
		for (int i = 3; i < n; i++) {
			scanf("%d", &c);
			if (a < b && b > c) {
				special++;
				S += b;
				if ((i - 1) % 2 != 0)
					xmax_impar = max(xmax_impar, b);
				else
					xmin_par = min(xmin_par, b);
			}
			a = b;
			b = c;
		}
		// verificare daca sunt gasiti copaci 'speciali' pe pozitii pare/impare
		// exista copaci 'speciali' daca val. xmax_impar/xmin_par s-a modificat
		if (xmax_impar != MAXIM)
			gasit_special_impar = 1;

		if (xmin_par != MINIM)
			gasit_special_par = 1;

		m_a = (double)S / special;
	}
	printf("%ld\n", S);
	// m_a: tratare caz impartire la zero
	// (numai doi copaci => nu exista copaci speciali)
	if (special != 0) {
		printf("%.7lf\n", m_a);
	} else {
		m_a = 0;
		printf("%.7lf\n", m_a);
	}
	// xmax_impar/xmin_par:
	//  tratare caz numai doi copaci
	if (destui_copaci == 0) {
		xmax_impar = 0;
		xmin_par = 0;
	} else {
		// exista destui copaci -- cazuri speciale
		if (gasit_special_impar == 0)
			xmax_impar = -1;
		if (gasit_special_par == 0)
			xmin_par = -1;
	}
	printf("%d\n", xmax_impar);
	printf("%d\n", xmin_par);
	return 0;
}
