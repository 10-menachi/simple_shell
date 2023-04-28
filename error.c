#include <stdio.h>
#include "shell.h"
void handle_error(char* command_name, int status)
{
  if (WIFEXITED(status)) {
    if (WEXITSTATUS(status) != 0) {
      char msg[100];
      int n = snprintf(msg, sizeof(msg), "Error: Command '%s' returned non-zero exit status %d\n", command_name, WEXITSTATUS(status));
      write(STDERR_FILENO, msg, n);
    }
  } else if (WIFSIGNALED(status)) {
    char msg[100];
    int n = snprintf(msg, sizeof(msg), "Error: Command '%s' terminated by signal %d\n", command_name, WTERMSIG(status));
    write(STDERR_FILENO, msg, n);
  }
}

