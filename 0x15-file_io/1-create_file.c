#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: reference  to  the file to be created.
 * @text_content: reference to the string.
 *
 * Return: (-1) on function failure .
 * else - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fb, a, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	fb = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	a = write(fb, text_content, length);

	if (fb == -1 || a == -1)
		return (-1);

	close(fb);

	return (1);
}
