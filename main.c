#include "shell.h"
#include <fcntl.h>

/**
 * main - Entry Point
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char prompt[MAX_INPUT_LENGTH];
	char *args[MAX_INPUT_LENGTH / 2 + 1];
	char error_msg[] = "Command not found.\n";
	char error_msg_fork[] = "Failed to fork.\n";
	pid_t pid;
	char *filename;
	int read_count;
	int fd = STDIN_FILENO;

	if (argc > 1)
	{
	filename = argv[1];
	fd =  open(filename, O_RDONLY);
		if (fd == -1)
		{
		perror("open");
		exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}

	while (1)
	{
	if (argc == 1)
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	read_count = read(fd, prompt, MAX_INPUT_LENGTH);
		if (read_count == 0)
			break;
		if (prompt[0] == '\n')
			continue;
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
			write(STDERR_FILENO, error_msg, sizeof(error_msg_fork));
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
