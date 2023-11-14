#include "shell.h"


Node *add_node_end(Node **head, char *str)
{
	Node *new;
	Node *ptr;
	char *copy;

	/**allocate memory for new node*/
	new = malloc(sizeof(Node));
	if (!new)
		return (NULL);
	/**duplicate the string*/
	copy = _strdup(str);
	if (copy == NULL)
	{
		free(new);
		return (NULL);
	}
	new -> directory = copy;
	new -> link = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		ptr = *head;
		/**transverse the list*/
		while (ptr -> link)
			ptr = ptr -> link;
		/**
		 * initialize the link of the prev last element to point to
		 * new node
		 */
		ptr -> link = new;
	}

	return(new);
}
