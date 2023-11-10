#include "shell.h"

/**
 * token_count - counts the number of tokens in a string based on a delimiter
 * @line: the input string to be tokenized
 * @delim: the character used to split the string in tokens
 *
 * Return: num of tokens
 */
int token_count(char *line, const char *delim)
{
	int count = 0;
	char *copy = NULL, *token = NULL;

	if (line == NULL)
		return (-1);
	copy = _strdup(line);
	if (copy == NULL)
		return (-1);
	token = strtok(copy, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(copy);

	return (count);
}
