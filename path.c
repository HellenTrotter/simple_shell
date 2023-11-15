#include "shell.h"

/**
 * find_path - searches the PATH to find if command exist in any directory
 * @command: command entered by user
 *
 * Return: Full path to the command
 */
char *find_path(char *command)
{
	char *line = NULL, *token = NULL, *line_cpy = NULL, *full_path = NULL;
	Node *head = NULL, *ptr = NULL;
	size_t len1, len2;

	if (access(command, F_OK | X_OK) == 0)/*check if executable exist*/
		return (_strdup(command));
	len1 = _strlen(command);
	line = _getenv("PATH");/*get the PATH environ value*/
	if (line == NULL)
		return (NULL);
	line_cpy = _strdup(line);
	if (line_cpy == NULL)
		return (NULL);
	token = strtok(line_cpy, ":");/*tokenize the value goten from getenv*/
	while (token != NULL)
	{
		add_node_end(&head, token);/*create new node in linked list*/
		token = strtok(NULL, ":");
	}
	ptr = head;
	while (ptr != NULL)
	{
		len2 = _strlen(ptr->directory);
		full_path = malloc(sizeof(char) * (len1 + len2 + 2));
		if (full_path == NULL)
		{
			cleanup(head, line_cpy);
		}
		full_cmd(full_path, ptr->directory, command);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			cleanup(head, line_cpy);
			return (full_path);
		}
		free(full_path);
		ptr = ptr->link;
	}
	cleanup(head, line_cpy);
	return (NULL);
}

/**
 * cleanup - used to free memory
 * @head: pointer to head node of a liked list
 * @ptr: pointer to a dynamically allocated memory
 *
 */
void cleanup(Node *head, char *ptr)
{
	if (head != NULL)
		free_list(head);
	if (ptr != NULL)
		free(ptr);
}


/**
 * full_cmd - creates a full path to the command entered by user
 * @full_path: pointer to the allocated memory for the full path
 * @directory: directory the command is being searched
 * @cmd: command entered by user
 *
 */
void full_cmd(char *full_path, char *directory, char *cmd)
{
	_strcpy(full_path, directory);
	_strcat(full_path, "/");
	_strcat(full_path, cmd);
}
