#include "shell.h"

/**
 * exit_shell - function that exits shell
 * @args: arrays of strings containing commands
 * @input: pointer to user input
 *
 * Return: always 0
 */

int exit_shell(char **args, char *input)
{
	if (input)
	{
		free(input);
	}
	free_arr(args);
	free(args);

	exit(0);
}
