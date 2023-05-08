#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - runs the program
 *@ac: checker
 *@avg: Average
 * Return: Always (0).
 */
int main(int ac, char **avg)
{
ssize_t n;

if (ac != 2)
{
dprintf(2, "Usage: %s filename\n", avg[0]);
exit(1);
}
n = read_textfile(avg[1], 114);
printf("\n(printed chars: %li)\n", n);
n = read_textfile(avg[1], 1024);
printf("\n(printed chars: %li)\n", n);
return (0);
}
