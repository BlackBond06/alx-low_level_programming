#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @a: number to find
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int a, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (a >> index) & 1;

	return (bit_val);
}
