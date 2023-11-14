#include "shell.h"

/**
 * main - entry point
 * @ac: arguments count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */

int main(int ac, char *argv[]);

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
			if (input == NULL)
				continue;
			arguments = parse(input);
			exec(arguments, envp, program);
			/* Free the memory allocated for the input arguments */

			free(input);
			free_arr(arguments);
			free(arguments);


		}
	}
	else
	{
		non_int(program);
	}

	return (0);
}
