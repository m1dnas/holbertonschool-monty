#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: struct
 * @line_number: line readed
 * Return: NULL
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(1);
	}
	printf("%i\n", (*stack)->n);
}

/**
* _pop - remove top element of the stack
* @stack: struct
* @line_number: line readed
* Return: NULL
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(1);
	}
	delete_endnode(stack);
}

/**
* _swap - swap last element
* @stack: head of list
* @line_number: line readed
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	unsigned int temp = 0;
	stack_t *p = (*stack);
	(void)line_number;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(1);
	}
	p = p->next;
	temp = (*stack)->n;
	(*stack)->n = p->n;
	p->n = temp;
}

/**
 * _add - adds top nodes
 * @stack: head of list
 * @line_number: line readed
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);
	(void)line_number;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		exit(1);
	}
	(*stack) = (*stack)->next;
	(*stack)->n = (*stack)->n + p->n;
	(*stack)->prev = NULL;
	free(p);
}
/**
 * _nop - does nothing
 * @stack: head of list
 * @line_number: line readed
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
