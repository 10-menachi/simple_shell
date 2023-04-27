#include "shell.h"

/**
 * strtrim - removes trailing wwhitespace from a string
 * @str: given string
 *
 * Return: trimmed string
 */

char *strtrim(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
		str++;
	if (*str == '\0')
		return (str);
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	end[1] = '\0';
	return (str);
}
