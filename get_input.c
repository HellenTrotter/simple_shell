#include "shell.h"


/**
 * get_input - reads input from the user and handles errors
 *
 * Return: character pointer
 */


void *get_input(void);

void *get_input(void)
{
	char *input_line = NULL;
	size_t buff_size = 0;
	ssize_t read_line;
	size_t len;

	/*Read a line of input from user*/
	read_line = getline(&input_line, &buff_size, stdin);


	/*Check if getline encountered an error or EOF*/
	if (read_line == -1)
	{
		if (input_line != NULL)
		{
			free(input_line);
		}
		write(STDIN_FILENO, "\n", 1);
		exit(0);
	}

	/*Remove the trailing newline character, if it exists*/
	len = _strlen(input_line);

	if (len > 0 && input_line[len - 1] == '\n')
	{
		input_line[len - 1] = '\0';
	}
	if (input_line[0] == '\0')
	{
		free(input_line);
		return (NULL);
	}

	return (input_line);

}
