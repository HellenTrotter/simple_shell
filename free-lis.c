#include "shell.h"

/**
 * free_list - frees singly linked list
 * @head: pointer to head node of linked list
 *
 */
void free_list(Node *head)
{
	Node *temp;

	while (head != NULL)
	{
		temp = head->link;
		free(head->directory);
		free(head);
		head = temp;
	}
}
