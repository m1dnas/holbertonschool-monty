#include "monty.h"
/**
* _pall - print size of a list
* @h: number
* @line_number: bytecode line number
* Return: 0
*/
void _pall(stack_t **h, unsigned int line_number)
{
	stack_t *len = NULL;

	if (!h || !*h)
		return;

	(void) line_number;
	len = *h;
	while (len != NULL)
	{
		printf("%d\n", len->n);
		len = len->next;
	}
}
/**
 * _push - add node to the start
 * @h: head of linked list
 * @line_number: bytecode line number
 * @n: integer
 */
void _push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
		return;

	if (isdigit(n) != 0 || (atoi(n) == 0 && *n != '0'))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_dnodeint(h, atoi(n)) == -1)
		{
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
}
