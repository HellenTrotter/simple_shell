#include "shell.h"

/**
 * token_count - counts the number of tokens in a string based on a delimiter
 * @line: the input string to be tokenized
 * @delim: the character used to split the string int tokens
 * Return: total number tokens
 */

int token_count(char *line, const char *delim)
{
	int count = 0;
	char *token;
	char *line_dup;

	/* Duplicate the input string using strdup*/
	line_dup = _strdup(line);

	/*Check if strdup allocation failed*/
	if (line_dup == NULL)
	{
		return (-1);
	}

	/* Use strtok to count tokens*/
	token = strtok(line, delim);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}

	free(line_dup);
	return (count);
}
