#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

extern char **environ;

char *_strdup(char *str);
size_t _strlen(const char *str);
void exec(char **args, char **envp, char *cmd);
char **parse(char *buf);
void free_arr(char **arr);
char *_strncpy(char *dest, const char *src, size_t n);
void *get_input(void);
int token_count(char *line, const char *delim);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, char *src);
void print_environment(void);
char *_getenv(const char *name);

#endif
