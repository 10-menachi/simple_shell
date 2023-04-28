#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0
 */

int main(void)
{
	char prompt[MAX_INPUT_LENGTH];
	char *args[2];
	char error_msg[] = "Command not found.\n";
	char error_msg_fork[] = "Failed to fork.\n";
	pid_t pid;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (fgets(prompt, MAX_INPUT_LENGTH, stdin) == NULL)
			break;
		prompt[strcspn(prompt, "\n")] = '\0';
		args[0] = prompt;
		args[1] = NULL;
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
			wait(NULL);
		}
	}
	return (0);
}
