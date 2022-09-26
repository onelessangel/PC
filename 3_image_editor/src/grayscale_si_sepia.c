#include "alocari.h"

void printre_tonuri_cenusii(unsigned char ***mat, int x1, int y1, int x2,
							int y2)
{
	y1 *= 3;
	y2 *= 3;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j += 3) {
			double gri;
			int s, elem1, elem2, elem3;
			elem1 = (int)(*mat)[i][j];
			elem2 = (int)(*mat)[i][j + 1];
			elem3 = (int)(*mat)[i][j + 2];
			s =  elem1 + elem2 + elem3;
			gri = (double)s / 3;
			if (gri - (int)gri >= 0.5) {
				(*mat)[i][j] = (unsigned char)((int)gri + 1);
				(*mat)[i][j + 1] = (unsigned char)((int)gri + 1);
				(*mat)[i][j + 2] = (unsigned char)((int)gri + 1);
			} else {
				(*mat)[i][j] = (unsigned char)(int)gri;
				(*mat)[i][j + 1] = (unsigned char)(int)gri;
				(*mat)[i][j + 2] = (unsigned char)(int)gri;
			}
		}
	}
}

void sepia(unsigned char ***mat, int x1, int y1, int x2, int y2,
		   short int max_intensitate)
{
	y1 *= 3;
	y2 *= 3;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j += 3) {
			double n_r, n_g, n_b, r, g, b;

			r = 0.393 * (int)(*mat)[i][j];
			g = 0.769 * (int)(*mat)[i][j + 1];
			b = 0.189 * (int)(*mat)[i][j + 2];
			n_r = r + g + b;

			r = 0.349 * (int)(*mat)[i][j];
			g = 0.686 * (int)(*mat)[i][j + 1];
			b = 0.168 * (int)(*mat)[i][j + 2];
			n_g = r + g + b;

			r = 0.272 * (int)(*mat)[i][j];
			g = 0.534 * (int)(*mat)[i][j + 1];
			b = 0.131 * (int)(*mat)[i][j + 2];
			n_b = r + g + b;

			schimbare_culoare(&(*mat)[i][j], n_r, max_intensitate);
			schimbare_culoare(&(*mat)[i][j + 1], n_g, max_intensitate);
			schimbare_culoare(&(*mat)[i][j + 2], n_b, max_intensitate);
		}
	}
}

void schimbare_culoare(unsigned char *x, double n, short int max_intensitate)
{
	if (n - (int)n >= 0.5)
		n = (int)n + 1;
	else
		n = (int)n;

	if (n > max_intensitate)
		*x = (unsigned char)max_intensitate;
	else
		*x = (unsigned char)n;
}
