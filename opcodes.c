#include "monty.h"
/**
* _pallfunction - print size of a list
* @h: number
* Return: 0
*/
size_t _pallfunction(const stack_t *h)
{
	int len = 0;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (0);
}

/**
* pushfunction - add new node
* @head: head
* @n: node
* Return: head
*/
stack_t *pushfunction(stack_t **head, const int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(dlistint_t));

	if (newnode != NULL)
	{
	newnode->n = n;
	newnode->next = (*head);
	newnode->prev = NULL;
	}
	while (newnode)
	{
		if ((*head) != NULL)
		{
			(*head)->prev = NULL;
			(*head)->prev = newnode;
		}
		(*head) = newnode;
		return (*head);
	}
	return (NULL);
}
