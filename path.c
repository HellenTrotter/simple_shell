#include "shell.h"

char *find_path(char *command)
{
	char *line = NULL, *token = NULL, *line_copy = NULL;
	char *full_path = NULL;
	Node *head = NULL, *ptr = NULL;
	size_t len1, len2;

	if (access(command, F_OK | X_OK) == 0)
		return (command);
	len2 = _strlen(command);
	line = _getenv("PATH");
	if (line == NULL)
		return (NULL);
	line_copy = strdup(line);
	if (line_copy == NULL)
		return (NULL);
	token = strtok(line_copy, ":");
	while (token != NULL)
	{
		ptr = add_node_end(&head, token);
		if (!ptr)
		{
			free(line_copy);
			free_list(head);
			return (NULL);
		}
		token = strtok(NULL, ":");
	}
	while (head != NULL)
	{
		len1 = _strlen(head -> directory);
		full_path = malloc(sizeof(char) * (len1 + len2 + 2));
		if (full_path == NULL)
		{
			free(line_copy);
			free_list(head);
			return (NULL);
		}
		full_cmd(full_path, head -> directory, command);
		if (access (full_path, F_OK | X_OK) == 0)
		{
			free_list(head);
			free(line_copy);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		head = head -> link;

	}
	free(line_copy);
	free_list(head);

	return (NULL);
}

void full_cmd(char *full_path,char *directory,char *cmd)
{
	_strcpy(full_path, directory);
	_strcat(full_path, "/");
	_strcat(full_path, cmd);
}
