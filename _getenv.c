#include "shell.h"

/**
 * _getenv - searches the environment variable to return the value of the
 * corrsponding name
 * @name: name of the environment variable
 *
 * Return: pointer to the the value of the name variable;
 */
char *_getenv(char *name)
{
	char **env = environ;
	char *value = NULL;
	size_t i, len;
	int cmp;
	/**check if name is a NULL pointer*/
	if (name == NULL)
		return (NULL);

	/**get the length of the variable parsed */
	len = _strlen(name);
	i = 0;
	/**loop untill env[i] == NULL*/
	while (env[i])
	{
		/**
		 * check if the first n bytes of the varible passed to the
		 * function and the environment variable is equal
		 */
		cmp = _strncmp(env[i], name, len);
		/**if it is equal, it returns 0*/
		if (cmp == 0)
		{
			/**
			 * perform pointer arithmetic so that the pointer
			 * points to the charcter after =
			 */
			value = (env[i] + len + 1);
			break;
		}
		i++;
	}
	if (value == NULL)
		return (NULL);
	return (value);
}
