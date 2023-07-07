#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: pointer to unsigned int
 * @index: index of the unsigned int
 *
 * Return: 1 on success, -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int j;
	j = 1UL << index;
	if (index > 63)
		return (-1);

	*n = (~j & *n);
	return (1);
}
