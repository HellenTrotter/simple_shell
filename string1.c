#include "shell.h"

/**
 * _strdup - duplicate to a new memory locatio
 * @str: pointer to string to duplicate
 *
 * Return: pointer to new memory location
 */
char *_strdup(char *str)
{
	int i, len;
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
	len = i + 1;
	ptr = malloc(sizeof(*ptr) * len);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';

	return (ptr);
}


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


/**
 * _strcpy - copies a string from src to dest includeing null byte
 * @dest: destination value
 * @src: source value
 *
 * Return: The pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];

	dest[a] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings character by character
 * @str1: first string
 * @str2: second string
 * Return: an integar
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 == *str2)
	{
		return (0); /* Strings are equal */
	}
	else if (*str1 < *str2)
	{
		return (-1);
	}
	else
	{
		return (1);
	}

}
