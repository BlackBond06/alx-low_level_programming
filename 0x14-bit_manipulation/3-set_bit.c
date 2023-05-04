#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @a: pointer to the number to change
 * @index: index of the bit to set to 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *a, unsigned int index)
{
	if (index > 63)
		return (-1);

	*a = ((1UL << index) | *a);
	return (1);
}
