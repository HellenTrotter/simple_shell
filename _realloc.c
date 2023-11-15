#include "shell.h"

/**
 * _realloc - reallocates memmory
 * @ptr: pointer to memory that needs to be reallocated
 * @old_size: old size of memory
 * @new_size: new size to be reallocated
 *
 * Return: pointer to the newly reallocated memory
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}
