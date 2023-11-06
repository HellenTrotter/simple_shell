#include "shell.h"

/**
 * _strdup - duplicate to a new memory locatio
 * @str: pointer to string to duplicate
 *
 * Return: pointer to new memory location
 */
char *_strdup(char *str)
{
	int i
	char *ptr = NULL;

	/**check if str is NULL*/
	if (str == NULL)
		return (NULL);
	i = 0;
	/*loop keeps running untill null byte*/
	while (str[i])
	{
		i++;
	}
	ptr = malloc(sizeof(*ptr) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';

	return (ptr);
}


#include "shell.h"

/**
 * _strlen - calculate the length of a character string
 * @str: pointer to a charectar
 *
 *Return: length of string
 */

size_t _strlen(const char *str)
{
	/*Initialize length to zero*/
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len); /*Return length*/
}
