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
void exec(char **args, char **envp, char *cmd);
char **parse(char *buf);
void free_arr(char **arr);

#endif
