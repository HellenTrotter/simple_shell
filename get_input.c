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
	size_t len;


	/*Read a line of input from user*/
	read_line = getline(&input_line, &buff_size, stdin);


	/*Check if getline encountered an error or EOF*/
	if (read_line == -1)
	{
		if (input_line != NULL)
		{
			perror("Error reading input");
			free(input_line);
		}
		exit(EXIT_SUCCESS);
	}

	write(STDOUT_FILENO, input_line, read_line);


	/*Remove the trailing newline character, if it exists*/
	len = _strlen(input_line);

	if (len > 0 && input_line[len - 1] == '\n')
	{
		input_line[len - 1] = '\0';
	}

	return (input_line);

}
