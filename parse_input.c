#include "shell.h"

/**
 * parse_input - splits given input into multiple words
 * @input: given input
 * @args: stores parsed input
 *
 */

void parse_input(char *input, char **args)
{
	char *arg;
	int i = 0;
	int is_space_only = 1;

	for (i = 0; input[i]; i++)
	{
		if (!isspace(input[i]))
		{
			is_space_only = 0;
			break;
		}
	}
	if (is_space_only)
	{
		args[0] = NULL;
		return;
	}
	i = 0;
	arg = strtok(input, " ");
	while (arg)
	{
		args[i++] = arg;
		arg = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (_strcmp(args[0], "exit") == 0)
		exit(0);
}
