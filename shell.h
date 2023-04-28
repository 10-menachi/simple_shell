#ifndef SHELL_H
#define SHELL_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 256

extern char **environ;

void shell_exit(void);
void parse_input(char *input, char **args);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int _strcmp(char *s1, char *s2);
char *strtrim(char *str);
char *find_path(char *command);
void handle_error(char* command_name, int status);
void env_builtin(void);
#endif /* SHELL_H */
