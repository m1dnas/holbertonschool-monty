#include "monty.h"

/**
* add_dnodeint_end - add a newnode at the end
* @head: pointer to head of list
* @n: node data
* Return: newnoded
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *last;
	stack_t *newnode;

	if (!head)
		return (NULL);

	newnode = malloc(sizeof(dlistint_t));

	if (!newnode)
		return (NULL);
	newnode->n = n;

	if (*head == NULL)
	{
		*head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
		return (newnode);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	newnode->next = NULL;
	newnode->prev = last;
	last->next = newnode;

	return (newnode);
}
/**
 * delete_end_node - deletes node at end
 * @h: pointer to head of doubly linked list
 */
void delete_endnode(stack_t **h)
{
	stack_t *del = NULL;

	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}
/**
* free_dlistint - free
* @head: address node
* Return: void
*/
void free_list(stack_t *head)
{
	stack_t *lib;

	while (head)
	{
		lib = head->next;
		free(head);
		head = lib;
	}
}
