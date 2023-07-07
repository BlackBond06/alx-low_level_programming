#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: unsigned int
 * @index: integer index value of unsigned int.
 *
 * Return: 1on success, or -1 if an error occurred.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int j;

	j = 1UL << index;
	if (index > 63)
		return (-1);

	*n = (j | *n);
	return (1);

}
