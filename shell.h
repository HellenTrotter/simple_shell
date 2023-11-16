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

#define BUFSIZE 1024
extern char **environ;

/**
 * struct node - singly linked list
 * @directory: string - (mallo'ed string)
 * @link: points to the next node
 *
 * Description: singly list node structure
 */
typedef struct node
{
	char *directory;
	struct node *link;
} Node;

char *_strdup(char *str);
size_t _strlen(const char *str);
int exec(char **args, char **envp, char *cmd);
char **parse(char *buf);
void free_arr(char **arr);
char *_strncpy(char *dest, const char *src, size_t n);
void *get_input(void);
int token_count(char *line, const char *delim);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, char *src);
void print_environment(void);
void non_int(char *program);
Node *add_node_end(Node **head, char *str);
char *_getenv(char *name);
int _strncmp(char *s1, char *s2, size_t n);
char *find_path(char *command);
char *_strcat(char *dest, char *src);
void full_cmd(char *full_path, char *directory, char *cmd);
void free_list(Node *head);
void full_message(char *message, char *cmd, char *arg);
void handler(int num);
char *err_message(char **args, char *cmd);
void cleanup(Node *head, char *ptr);
ssize_t _getline(char **lineptr, size_t *n, int fd);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strtok(char *str, const char *delim);
int exit_shell(char **args, char *input);
int print_environment(char **args, char 8input);

#endif
