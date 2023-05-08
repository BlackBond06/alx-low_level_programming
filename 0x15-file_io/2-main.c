#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *@avg: average
 *@ac : control flow handler
 * Return: Always (0) success.
 */
int main(int ac, char **avg)
{
int res;

if (ac != 3)
{
dprintf(2, "Usage: %s filename text\n", avg[0]);
exit(1);
}
res = append_text_to_file(avg[1], avg[2]);
printf("-> %i)\n", res);
return (0);
}
