#include "alocari.h"

int min(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}

int max(int x, int y)
{
	if (x < y)
		return y;
	else
		return x;
}
