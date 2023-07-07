#include "main.h"


/**
 * binary_to_uint - Converts binary num to unsigned in
 *
 * Parameter:
 * @b: string representing the binary num
 *
 * Variables:
 * j: int value used to iterate the string  binary num
 * converted_value: value returned on conversion
 *
 * Return: converted_value
 */

unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int converted_value = 0;

	if (!b)
		return (0);

	for (j = 0; b[j]; j++)
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		converted_value = 2 * converted_value + (b[j] - '0');
	}

	return (converted_value);
}
