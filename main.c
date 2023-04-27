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
	pid_t pid;
	char *cmd;

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(prompt, MAX_INPUT_LENGTH, stdin) == NULL)
			break;
		prompt[strcspn(prompt, "\n")] = '\0';
		parse_input(prompt, args);
		cmd = find_path(args[0]);
		if (!cmd)
		{
			fprintf(stderr, "Command not found.\n");
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execvp(args[0], args);
			fprintf(stderr, "Command not found.\n");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			fprintf(stderr, "Failed to fork.\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
		free(cmd);
	}
	return (0);
}
