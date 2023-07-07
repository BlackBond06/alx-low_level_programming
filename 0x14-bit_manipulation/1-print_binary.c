#include "main.h"

/**
 * print_binary -  prints the binary representation of a num
 *
 * Parameter
 * @n: int converted to its binary value
 *
 */

void print_binary(unsigned long int n)
{
	int j;
	int counter = 0;
	unsigned long int current_value;

	for (j = 63; j >= 0; j--)
	{
		current_value = n >> j;

		if (current_value & 1)
		{
			_putchar('1');
			counter++;
		}
		else if (counter)
			_putchar('0');
	}
	if (!counter)
		_putchar('0');
}
