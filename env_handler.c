#include "shell.h"

/**
 * set_env - sets or updates an environment variable
 * @name: name of environment variable
 * @value: value to set the environment variable
 * @overwrite: an integer
 * Return: interger value
 */

int set_env(const char *name, const char *value, int overwrite)
{
	int result = setenv(name, value, overwrite);

	if (result != 0)
	{
		perror("Error setting environment variable");
		return (-1);
	}

	return (0);
}


/**
 * setenv_function - sets or updates an environment variable
 * @arguments: array of strings containing the command and arguments
 */

void setenv_function(char **arguments)
{
	/*Check if the command is setenv*/
	if (_strcmp(arguments[0], "setenv") == 0)
	{
		/*Check if both variable name and value are provided*/
		if (arguments[1] != NULL && arguments[2] != NULL)
		{
			/* Try to set the environment variable*/
			if (set_env(arguments[1], arguments[2], 1) == 0)
			{
				write(STDOUT_FILENO, "Environment variable set successfully!\n", 38);
			}
		       	else
			{
				write(STDERR_FILENO, "Failed to set variable.\n", 22);
			}

		}
		else
		{
			write(STDERR_FILENO, "Usage: setenv VARIABLE_NAME VARIABLE_VALUE\n", 43);
		}
	}
}

/**
 * unset_env - removes an environment variable
 * @name: name of environment variable
 * Return: 0 on success
 */

int unset_env(const char *name)
{
	if (unsetenv(name) != 0)
	{
		perror("Error unsetting environment variable");
		return (-1);
	}

	return (0);
}


/**
 * unsetenv_function - unsets an environment variable
 * @arguments: array of strings containing the command and arguments
 */

void unsetenv_function(char **arguments)
{
	if (_strcmp(arguments[0], "unsetenv") == 0)
	{
		if (arguments[1] != NULL)
		{
			if (unset_env(arguments[1]) == 0)
			{
				write(STDOUT_FILENO, "Environment variable uset successfully!\n", 40);
			}
			else
			{
				write(STDERR_FILENO, "Failed to unset variable.\n", 26);
			}
		}
		else
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE_NAME\n", 30);
		}
	}
}
