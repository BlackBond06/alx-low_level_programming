#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- reads text file and prints it to the POSIX standard output.
 * @filename: file to be read
 * @letters: num of letters to be counted
 * Return: m- num of bytes read and printed
 * 0: value if  function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fb;
	ssize_t m;
	ssize_t t;

	fb = open(filename, O_RDONLY);
	if (fb == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fb, buf, letters);
	m = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fb);
	return (m);
}
