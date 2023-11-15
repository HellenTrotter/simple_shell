#include "shell.h"

/**
 * is_digit - checks whether a character is a digit
 * @character: single paramether which is a character
 * Return: 1 if character is a digit
 */

int is_digit(char character)
{
	return (character >= '0' && character <= '9');
}

/**
 * _atoi - converts a string to an integer
 * @str: input string to convert
 * Return:converted string
 */

int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
	{
		str++;
	}

	if (*str == '-' || *str == '+')
	{
		sign = (*str++ == '-') ? -1 : 1;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str++ - '0');
	}

	return (sign * result);
}


/**
 * print_error - prints an error message to stderr
 * @program: name of program
 * @message: error message to print
 * Return: void
 */

void print_error(const char *program, const char *message)
{
	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": exit: illegal number: ", 24);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
}



/**
 * exit_cmd - handles exit command
 * @arg: argument
 * @argv: argument vector
 * Return: void
 */

void exit_cmd(char *arg, char **argv)
{
	int i;
	int status;

	/*If there is no argument, exit with success*/
	if (arg == NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}

		free(argv);

		exit(EXIT_SUCCESS);
	}

	/*If the argument is not a number, print error*/
	for (i = 0; arg[i]; i++)
	{
		if (!is_digit(arg[i]))
		{
			print_error(argv[0], arg);
			break;
		}
	}

	status = _atoi(arg);
	/*Free individual arguments in argv*/
	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);

	exit(status);
}
