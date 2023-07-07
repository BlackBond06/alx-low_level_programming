#include "main.h"

/**
 * flip_bits - returns the number of bits you would need
 * to flip to get from one number to another.
 * @n: para1
 * @m: para2
 *
 * Return: number of bits changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int j = 0;
	int counter = 0;
	unsigned long int curr;
	unsigned long int not_included = n ^ m;

	for (j = 63; j >= 0; j--)
	{
	curr = not_included >> j;
		if (curr & 1)
			counter++;
	}

	return (counter);
}
