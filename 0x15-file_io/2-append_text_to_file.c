#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: reference to the file in memory.
 * @text_content: String to be appended.
 *
 * Return: -1 if function fails or file is NULL.
 * else - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, m, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	m = write(o, text_content, length);

	if (o == -1 || m == -1)
		return (-1);

	close(o);

	return (1);
}
