#include "shell.h"

/**
 * main - entry point
 * @ac: arguments count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */

int main(int ac, char *argv[])
{
	char *prmpt = "Welcome to our shell ~$$ ";
	char *input;
	char **arguments;
	char **envp = NULL;
	char *program = argv[0];

	(void) ac;
	if (isatty(STDIN_FILENO))
	{
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

			exec(arguments, envp, program);
			/* Free the memory allocated for the input arguments */
			free(input);
			free_arr(arguments);
			free(arguments);


		}
	}

	return (0);
}
