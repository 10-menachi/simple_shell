/**
* find_path - Finds command's full path in directories listed in PATH.
* return: full path if command is found and is executable, else returns NULL.
*
*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 4096

char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char *path_buffer = malloc(MAX_PATH_LENGTH * sizeof(char));
	int path_len;
	char *full_path;
	struct stat buffer;

	while (dir != NULL)
	{
	path_len = strlen(dir) + strlen(command) + 2;
	full_path = malloc(path_len * sizeof(char));
	sprintf(full_path, "%s/%s", dir, command);

	if (stat(full_path, &buffer) == 0 && S_ISREG(buffer.st_mode)
			&& (buffer.st_mode & S_IXUSR))
	{
	free(path_buffer);
	return (full_path);
	}

	free(full_path);
	dir = strtok(NULL, ":");
	}

	free(path_buffer);
	return (NULL);
}
