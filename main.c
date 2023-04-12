#include "main.h"

/**
 * main - Entry Point
 *
 * Return: 0
 */

int main(void)
{
	char prompt[MAX_INPUT_LENGTH];
	pid_t pid;

	while (1)
	{
		printf("$ ");
		if (fgets(prompt, MAX_INPUT_LENGTH, stdin) == NULL)
			break;
		prompt[strcspn(prompt, "\n")] = '\0';
		pid = fork();
		if (pid == 0)
		{
			execlp(prompt, prompt, NULL);
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
	}
	return (0);
}
