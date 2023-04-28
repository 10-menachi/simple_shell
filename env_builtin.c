#include "shell.h"

/**
 * env_builtin - handles printing of env variables
 *
 */

void env_builtin(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
