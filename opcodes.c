#include "monty.h"
char *global_value;
int is_number(const char *token);
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
 */
void _push(stack_t **h, unsigned int line_number)
{
	if (!h)
		return;
	if (is_number(global_value) == -1)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_dnodeint(h, atoi(global_value)) == -1)
		{
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
}
/**
* is_number - is number or not
* @token: token
* Return: 1 if it's digit
*/
int is_number(const char *token)
{
	int i = 0;

	if (token == NULL)
		return (-1);
	if (token[0] == '-')
		i = 1;
	for (; token[i] != '\0'; i++)
	{
		if (isdigit(token[i]) == 0)
		{
			return (-1);
		}
	}
	return (1);
}
