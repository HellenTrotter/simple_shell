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
	char *input = NULL;
	char **arguments;
	char **envp = NULL;
	char *program = argv[0];

	(void) ac;
	signal(SIGINT, handler);
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(STDOUT_FILENO, prmpt, _strlen(prmpt)); /* Display the shell prompt */

			input = get_input();
			if (input == NULL)
				continue;
			arguments = parse(input);
			main_exec_file(arguments, envp, program, input);

			if (_strcmp(arguments[0], "setenv") == 0)
			{
				setenv_function(arguments);
			}
			else if (_strcmp(arguments[0], "unsetenv") == 0)
			{
				unsetenv_function(arguments);
			}
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
