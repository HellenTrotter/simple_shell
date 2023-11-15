#include "shell.h"


/**
 * print_environment - displays environment variables
 * Return: 0 (success)
 */

void print_environment(void)
{
	char **env_ptr = environ;

	while (*env_ptr)
	{
		size_t len = _strlen(*env_ptr);

		write(STDOUT_FILENO, *env_ptr, len);
		write(STDOUT_FILENO, "\n", 1);
		env_ptr++;
	}
}
