#include <stdio.h>
#include "main.h"
/**
 * main - main function
 *
 * Return: Always (0) success
 */
int main(void)
{
int a;

a = get_endianness();
if (a != 0)
{
printf("Little Endian\n");
}
else
{
printf("Big Endian\n");
}
return (0);
}
