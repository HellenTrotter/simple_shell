#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0 (success)
 */

int main(void)
{
	char *prmpt = "Welcome to our shell ~$$ ";
	char *input;
	char **arguments;

	while (1)
	{
		write(STDOUT_FILENO, prmpt, _strlen(prmpt)); /* Display the shell prompt */

		input = get_input();
		arguments = parse(input);

		if (arguments != NULL && arguments[0] != NULL)
		{
			if (_strcmp(arguments[0], "exit") == 0)
			{
				free(input);
				free_arr(arguments);
				exit(0); /* Exit shell successfully */
			}
		}

		/* Free the memory allocated for the input arguments */
		free(input);
		free_arr(arguments);


	}

	return (0);
}
