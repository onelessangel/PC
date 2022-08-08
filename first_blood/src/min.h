#include <stdio.h>

int min(int a, int b)
{
	int minim;
	if (a < b)
		minim = a;
	else
		minim = b;
	return minim;
}
