#include <stdio.h>

int max(int a, int b)
{
	int maxim;
	if (b < a)
		maxim = a;
	else
		maxim = b;
	return maxim;
}
