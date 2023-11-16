#include "shell.h"

/**
 * print_environment - displays environment variables
 * @args: array of string
 * @input: pointer to user input
 *
 * Return: always 0
 */

int print_environment(char **args, char *input)
{
	char **env_pnt = environ;
	int i;

	(void)args;
	(void)input;

	/*Itrate through the enviroment variables and print them*/
	i = 0;

	while (env_ptr[i])
	{
		size_t len = _strlen(env_ptr[i]);

		write(STDOUT_FILENO, env_ptr[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}
