#include "shell.h"
/**
 * non_int - program that executes program in non interactive shell
 * @program: name of program
 *
 */
void non_int(char *program)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t read_bytes;
	char **args = NULL;
	char **envp = NULL;

	while ((read_bytes = getline(&input, &bufsize, stdin)) != -1)
	{
		/*Remove newline character, if present*/
		if (input[read_bytes - 1] == '\n')
			input[read_bytes - 1] = '\0';
		/*parse input to an array of strings*/
		args = parse(input);
		/*execute the program*/
		exec(args, envp, program);
		free_arr(args);
		free(args);
	}

	free(input);
}
