#include "shell.h"

/**
 * parse_input - splits given input into multiple words
 * @input: given input
 * @args: stores parsed input
 *
 */

void parse_input(char *input, char **args)
{
	char *arg = strtok(input, " ");
	int i = 0;

	while (arg)
	{
		args[i++] = arg;
		arg = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (_strcmp(args[0], "exit") == 0)
		exit(0);
}
