#include "main.h"

/**
 * get_bit -  function that returns the value of a bit at a given index.
 *
 * @n: unsigned int
 * @index: index of unsigned int
 * Return: the value of the bit at index index or -1 if an error occured
 *
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val_at_idx;

	if (index > 63)
		return (-1);

	bit_val_at_idx = (n >> index) & 1;

	return (bit_val_at_idx);

}
