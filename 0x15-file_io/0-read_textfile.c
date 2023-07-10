#include "main.h"



/**
 * read_textfile- Reads a text file and prints it to the POSIX standard output.
 * @filename: The input text that will be read
 * @letters: Input text letters
 * Return: bytes_num -  num of bytes read and printed
 * 0 on failure or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_descriptor;
	ssize_t bytes_num;
	ssize_t x;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	x = read(file_descriptor, buffer, letters);
	bytes_num = write(STDOUT_FILENO, buffer, x);

	free(buffer);
	close(file_descriptor);
	return (bytes_num);
}
