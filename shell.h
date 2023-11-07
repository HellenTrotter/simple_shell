#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

char *_strdup(char *str);
size_t _strlen(const char *str);
char *_strncpy(char *dest, const char *src, size_t n);
void *get_input(void);
int token_count(char *line, char *delim);

#endif
