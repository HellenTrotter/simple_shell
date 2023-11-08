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

		/* Free the memory allocated for the input arguments */
		free(input);
		free_arr(arguments);


	}

	return (0);
}
