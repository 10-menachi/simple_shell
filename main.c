#include "shell.h"

/**
 * main - Entry Point
 *
 * Return: 0
 */

int main(void)
{
	char prompt[MAX_INPUT_LENGTH];
	char *args[MAX_INPUT_LENGTH / 2 + 1];
	char error_msg[] = "Command not found.\n";
	char error_msg_fork[] = "Failed to fork.\n";
	pid_t pid;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (fgets(prompt, MAX_INPUT_LENGTH, stdin) == NULL)
			break;
		prompt[strcspn(prompt, "\n")] = '\0';
		parse_input(prompt, args);
		pid = fork();
		if (pid == 0)
		{
			execvp(args[0], args);
			write(STDERR_FILENO, error_msg, sizeof(error_msg));
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			write(STDERR_FILENO, error_msg_fork, sizeof(error_msg_fork));
			exit(EXIT_FAILURE);
		}
		else
		{
			if (_strcmp(args[0], "env") == 0)
				env_builtin();
			else
				wait(NULL);
		}
	}
	return (0);
}
