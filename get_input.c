#include "shell.h"


/**
 * get_input - reads input from the user and handles errors
 *
 * Return: character pointer
 */


void *get_input(void);

void *get_input(void)
{
	char *input_line;
	size_t buff_size = 0;
	ssize_t read_line;
	char *error;
	size_t len;

	/*Read a line of input from user*/
	read_line = getline(&input_line, &buff_size, stdin);

	/*Check if getline encountered an error or EOF*/
	if (read_line == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			if (feof(stdin))
			{
				free(input_line);
				exit(0);
			}
			else
			{
				perror("Error: No such file or directory");
			}
		}
		else
		{
			perror("Error reading input");
		}

		/*Free input_line buffer and exit with failure status*/
		free(input_line);
		exit(1);
	}

	/*Remove the trailing newline character, if it exists*/
	size_t len = _strlen(input_line);

	if (len > 0 && input_line[len - 1] == '\n')
	{
		input_line[len - 1] = '\0';
	}

	return (input_line);

}
