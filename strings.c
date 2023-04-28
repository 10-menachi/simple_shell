#include "shell.h"
/**
  * _strcmp - Compares two strings
  * @s1: The first string
  * @s2: The second string
  *
  * Return: int value
  */


int _strcmp(char *s1, char *s2)
{
	int a = 0, b = 0, c = 0, r = 0, lim;

	while (s1[a])
	{
		a++;
	}
	while (s2[b])
	{
		b++;
	}
	if (a <= b)
	{
		lim = a;
	}
	else
	{
		lim = b;
	}
	while (c <= lim)
	{
		if (s1[c] == s2[c])
		{
			c++;
			continue;
		}
		else
		{
			r = s1[c] - s2[c];
			break;
		}
	}
	return (r);
}


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

/**
 * _strtok - tokenizes a string
 * @str: the string to be tokenized
 * @delim: the delimiter to use
 * Return: a pointer to the next token
 */
char *_strtok(char *str, const char *delim)
{
	static char *last;
	char *tok;
	const char *delim_pos;

	if (str)
		last = str;
	if (!*last)
		return (NULL);
	tok = last;
	while (*last)
	{
		delim_pos = delim;
		while (*delim_pos)
		{
			if (*last == *delim_pos)
			{
				*last = '\0';
				last++;
				if (*tok)
					return (tok);
				tok = last;
				break;
			}
			delim_pos++;
		}
		last++;
	}
	return (tok);
}
