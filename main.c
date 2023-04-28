#include "shell.h"

/**
 * execute_command - fork and execute the given command
 * @args: array of arguments (including the command) to execute
 * Return: exit status of the executed command
 */

int execute_command(char **args)
{
	char error_msg[] = "Command not found.\n";
	char error_msg_fork[] = "Failed to fork.\n";
	pid_t pid;
	int status, exit_status = 0;

	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		write(STDERR_FILENO, error_msg, sizeof(error_msg));
		exit(127);
	}
	else if (pid < 0)
	{
		write(STDERR_FILENO, error_msg_fork, sizeof(error_msg_fork));
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}

	return (exit_status);
}

/**
 * shell_loop - main loop of the shell
 * @exit_status: exit status
 */
void shell_loop(int *exit_status)
{
	char prompt[MAX_INPUT_LENGTH], *args[MAX_INPUT_LENGTH / 2 + 1];
	int show_prompt = isatty(STDIN_FILENO);
	char *comment_start;

	while (1)
	{
		if (show_prompt)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (fgets(prompt, MAX_INPUT_LENGTH, stdin) == NULL)
			break;
		comment_start = strchr(prompt, '#');
		if (comment_start != NULL)
			*comment_start = '\0';
		prompt[strcspn(prompt, "\n")] = '\0';
		parse_input(prompt, args);
		if (args[0] == NULL)
			continue;
		if (_strcmp(args[0], "exit") == 0)
			return;
		if (_strcmp(args[0], "env") == 0)
		{
			env_builtin();
			continue;
		}
		*exit_status = execute_command(args);
	}
}

#include "shell.h"

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int exit_status = 0;

	shell_loop(&exit_status);
	return (0);
}

