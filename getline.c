#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
    static char buffer[BUFFER_SIZE];
    static size_t buffer_pos = 0;
    size_t line_pos = 0;
    char c;

    if (*lineptr == NULL) {
        *lineptr = malloc(*n);
        if (*lineptr == NULL) {
            return (-1);
        }
    }

    while (1) {
        if (buffer_pos == 0) {
            size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, stream);
            if (bytes_read == 0) {
                return (-1);
            }
        }
        c = buffer[buffer_pos++];
        if (c == '\n' || buffer_pos == BUFFER_SIZE) {
            (*lineptr)[line_pos++] = '\0';
            *n = line_pos;
            buffer_pos = 0;
            return (line_pos);
        }
        (*lineptr)[line_pos++] = c;
        if (line_pos >= *n) {
            *n += BUFFER_SIZE;
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL) {
                return (-1);
            }
        }
    }
}
