#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
/**
* my_getline - reads a line from the given input stream
* @lineptr: pointer to pointer to a character array that stores the input line
* @n: pointer to a size_t variable that holds the size of the character array
* @stream: a pointer to stdin
*
* Return: number of characters read, including the terminating null byte
*/

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos;
	size_t line_pos = 0;
	char c;

	buffer_pos = 0;
	if (*lineptr == NULL)
		*lineptr = malloc(*n);
	if (*lineptr == NULL)
		return (-1);
	while (1)
	{
	if (buffer_pos == 0)
		size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, stream);
	if (bytes_read == 0)
		return (-1);
	}
	c = buffer[buffer_pos++];
	if (c == '\n' || buffer_pos == BUFFER_SIZE)
	{
	(*lineptr)[line_pos++] = '\0';
		*n = line_pos;
		buffer_pos = 0;
		return (line_pos);
	}
	(*lineptr)[line_pos++] = c;
	if (line_pos >= *n)
	{
	*n += BUFFER_SIZE;
	*lineptr = realloc(*lineptr, *n);
		if (*lineptr == NULL)
			return (-1);
	}
	}
}
