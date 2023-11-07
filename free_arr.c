#include "shell.h"

/**
 * free_arr - free array of strings
 * @arr: string array
 *
 */
void free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}

}
