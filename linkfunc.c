#include "monty.h"
/**
* print_list - Print lists
* @h: list
* Return: count
*/
size_t print_list(const stack_t *h)
{
	size_t i = 0;

	while (h)
	{
		if (&h->n != NULL)
			printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

/**
* add_dnodeint - add new node
* @h: head
* @n: node
* Return: head
*/
int add_dnodeint(stack_t **h, int n)
{
	stack_t *newnode;

	if (!h)
		return (-1);

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	newnode->n = n;

	if (*h == NULL)
	{
		*h = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else
	{
		newnode->next = *h;
		(*h)->prev = newnode;
		*h = newnode;
	}
	return (0);
}
/**
 * delete_endnode - deletes node at end
 * @h: pointer to head of doubly linked list
 */
void delete_endnode(stack_t **h)
{
	stack_t *delete = NULL;

	delete = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(delete);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(delete);
	}
}
/**
* free_list - free
* @h: address node
* Return: void
*/
void free_list(stack_t **h)
{
	stack_t *p = (*h);

	for (; p; p = p->next)
	{
		free(p);
	}
}
