#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always (0) on success.
 */
int main(void)
{
unsigned long int a;

a = 1024;
clear_bit(&a, 10);
printf("%lu\n", a);
a = 0;
clear_bit(&a, 10);
printf("%lu\n", a);
a = 98;
clear_bit(&a, 1);
printf("%lu\n", a);
return (0);
}
