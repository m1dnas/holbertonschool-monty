#include "monty.h"
/**
* pall - print size of a list
* @h: number
* @line_number: bytecode line number
* Return: 0
*/
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *len = NULL;

	if (!h || !*h)
		return;

	(void) line_number;
	len = *h
	while (len != NULL)
	{
		printf("%d\n", len->n)
		len = len->next;
	}
}
/**
 * push - add node to the start
 * @h: head of linked list
 * @line_number: bytecode line number
 */
void push(stack_t **h, unsigned int line_number)
{
	const char *count;

	if (!h)
		return;

	if (isdigit(atoi(count)) != 0)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
}
