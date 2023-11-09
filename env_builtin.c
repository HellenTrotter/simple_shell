#include "shell.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @name: the name of the environment variable
 * Return: a pointer to the value of environment variable
 */

char *_getenv(const char *name)
{
	int k;
	char *env_var;
	char *equal;

	for (k = 0; environ[k] != NULL; k++)
	{
		env_var = environ[k];
		equal = NULL;
	}

	for (equal = env_var; *equal != '\0' && *equal != '='; equal++)
	{
		if (*equal == '=')
		{
			size_t name_len = (size_t)(equal - env_var);
			int i = 1;
			size_t l;

			while (l < name_len)
			{
				if (env_var[l] != name[l])
				{
					i = 0;
					break;
				}
				l++;
			}

			if (i && name[name_len] == '\0')
			{
				return (equal + 1);
			}
		}
	}

	return (NULL);
}

/**
 * print_environment - displays environment variables
 * Return: 0 (success)
 */

void print_environment(void)
{
	char **env_ptr = environ;

	while (*env_ptr)
	{
		size_t len = _strlen(*env_ptr);

		write(STDOUT_FILENO, *env_ptr, len);
		write(STDOUT_FILENO, "\n", 1);
		env_ptr++;
	}
}
