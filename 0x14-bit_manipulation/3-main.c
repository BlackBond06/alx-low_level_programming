#include <stdio.h>
#include "main.h"


/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
unsigned long int a;

a = 1024;
set_bit(&a, 5);
printf("%lu\n", a);
a = 0;
set_bit(&a, 10);
printf("%lu\n", a);
a = 98;
set_bit(&a, 0);
printf("%lu\n", a);
return (0);
}
