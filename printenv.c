#include "shell.h"


/**
 * print_environment - displays environment variables
 *
 * Return: none
 */

void print_environment(void)
{
	char **env_ptr = environ;

	/*Itrate through the environment variables and print them*/
	while (*env_ptr)
	{
		size_t len = _strlen(*env_ptr);

		write(STDOUT_FILENO, *env_ptr, len);
		write(STDOUT_FILENO, "\n", 1);
		env_ptr++;
	}
}
