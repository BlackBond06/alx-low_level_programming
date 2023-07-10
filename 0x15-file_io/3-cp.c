#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buff(char *file);
void close_file(int file_descriptor);

/**
 * create_buff - Assigns 1024 bytes to a buffer.
 * @file: buffer name.
 *
 * Return: pointer to the newly-allocated buff.
 */

char *create_buff(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - Shut down file descriptor.
 * @file_descriptor: file descriptor to be shut down.
 */

void close_file(int file_descriptor)
{
	int cls_file;

	cls_file = close(file_descriptor);

	if (cls_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}

/**
 * main - Entry point
 * @argc: argument count.
 * @argv: Array.
 *
 * Return: 0 on success.
 *
 */
int main(int argc, char *argv[])
{
	int old_file, new_file, rd, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buff(argv[2]);
	old_file = open(argv[1], O_RDONLY);
	rd = read(old_file, buffer, 1024);
	new_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (old_file == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wr = write(new_file, buffer, rd);
		if (new_file == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		rd = read(old_file, buffer, 1024);
		new_file = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buffer);
	close_file(old_file);
	close_file(new_file);

	return (0);
}
