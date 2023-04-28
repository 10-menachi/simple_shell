#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
* execute - executes
* @args: arguments
*/
void execute(char **args);
void execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
	write(STDERR_FILENO, "fork error\n", 11);
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	if (execvp(args[0], args) == -1)
	{
	write(STDERR_FILENO, "execvp error\n", 13);
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	do {
	if (waitpid(pid, &status, WUNTRACED) == -1)
	{
	write(STDERR_FILENO, "waitpid error\n", 14);
	exit(EXIT_FAILURE);
	}
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	handle_error(args[0], status);
	}
}

