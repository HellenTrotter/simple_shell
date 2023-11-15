#include "shell.h"

/**
 * _strtok - tokenizes string
 * @str: string to be tokenized
 * @delim: delimeter used
 *
 * Return: pointer to the token created
 */
char *_strtok(char *str, const char *delim)
{
	static char *ptr;
	char *token;

	if (str != NULL)
		ptr = str;
	if (ptr == NULL)
		return (NULL);
	while (*ptr != '\0' && *ptr == *delim)
		ptr++;
	if (*ptr == '\0')
	{
		ptr = NULL;
		return (NULL);
	}
	token = ptr;
	while (*ptr != '\0' && *ptr != *delim)
		ptr++;
	if (*ptr != '\0')
	{
		*ptr = '\0';
		ptr++;
	}
	else
	{
		ptr = NULL;
	}

	return (token);
}
