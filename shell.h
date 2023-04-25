#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 256

void parse_input(char *input, char **args);
size_t my_getline(char **lineptr, size_t *n, FILE *stream);
#endif /* SHELL_H */
