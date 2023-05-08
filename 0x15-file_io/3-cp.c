#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fb);

/**
 * create_buffer - creates 1024 memory space for  buffer.
 * @file: file name buffer char is stored in
 *
 * Return: A reference to the buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes descriptor files.
 * @fb: Descriptor of file to close.
 */
void close_file(int fb)
{
	int a;

	a = close(fb);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fb);
		exit(100);
	}
}

/**
 * main - duplicates contents of a file to new file.
 * @argb: number of arguments given to the program.
 * @argd: array of references to the arguments.
 *
 * Return: Always (0) success.
 *
 */
int main(int argb, char *argd[])
{
	int from, to, r, w;
	char *buffer;

	if (argb != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argd[2]);
	from = open(argd[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argd[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argd[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argd[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argd[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
