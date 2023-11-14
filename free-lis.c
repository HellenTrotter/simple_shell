#include "shell.h"

void free_list(Node *head)
{
	Node *temp;

	while(head != NULL)
	{
		temp = head -> link;
		free(head -> directory);
		free(head);
		head = temp;
	}
}
