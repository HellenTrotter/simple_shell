#include "shell.h"

/**
 * parse - accepts input from user, tokenizes it and returns string arr
 *@buf: buffer containing user input
 *
 * Return: Array of strings
 */
char **parse(char *buf)
{
	char *copy = NULL, *token = NULL;
	const char *delim = " \n";
	char **args = NULL;
	int count, i;

	/**check if buf is empty*/
	if (buf == NULL)
		return (NULL);
	/**duplicate the user input and put in a dynamically alloc memory*/
	copy = _strdup(buf);
	if (!copy)
		return (NULL);
	/**get num of token in user input*/
	count = token_count(copy, delim);
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
	{
		free(copy);
		return (NULL);
	}

	/**tokenize user input using strtok*/
	token = strtok(copy, delim);
	if (!token)
		return (NULL);
	for (i = 0; token != NULL; i++)
	{
		args[i] = (malloc(sizeof(char) * (_strlen(token) + 1));
		if (!args[i])
		{
			free_arr(args);
			free(args);
			free(copy);
			return (NULL);
		}
		_strcpy(args[i], token);
		token = strtok(NULL, delim)
	}
	args[i] = NULL;
	free(copy);
}
