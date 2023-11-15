#include "shell.h"

/**
 * _strncmp - compares two strings
 * @s1: first string
 * @s2: second string
 *@n: num of characters to compre
 * Return: An integar less than 0, greater than 0 or equal to zero if s1 is
 * less than,greater than or equal to s2 respectively
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t a;

	a = 0;
	while ((a < n) && (s1[a] && s2[a]))
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}

	return (0);
}

/**
 * _strcat -  Concatenates string pointed to by src to dest
 * @dest: destination string
 * @src: string that will be appended to dest
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int a;

	i = 0;
	while (dest[i])
		i++;
	for (a = 0; src[a] != '\0'; a++)
	{
		dest[i++] = src[a];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _memcpy - Copies memory area
 * @dest: ponter to the meory address to be copied to
 * @src: ponter to the memory address to be copied from
 * @n: number of bytes to be copied
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = src[i];
	}

	return (dest);
}
