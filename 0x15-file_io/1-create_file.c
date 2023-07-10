#include "main.h"

/**
 * create_file - creates a file.
 * @filename:  pointer to the name of the file to be created.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: -1 0n failure.
 * returns 1 on success.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, x, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(file_descriptor, text_content, length);

	if (file_descriptor == -1 || x == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
