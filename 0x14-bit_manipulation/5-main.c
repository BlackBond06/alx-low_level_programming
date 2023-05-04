#include <stdio.h>
#include "main.h"
/**
 * main - check the code
 *
 * Return: Always (0) success.
 */
int main(void)
{
unsigned int a;

a = flip_bits(1024, 1);
printf("%u\n", a);
a = flip_bits(402, 98);
printf("%u\n", a);
a = flip_bits(1024, 3);
printf("%u\n", a);
a = flip_bits(1024, 1025);
printf("%u\n", a);
return (0);
}
