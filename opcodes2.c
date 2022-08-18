#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * stack - 
 * line_number - 
 * Return: 
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty", line_number);
		exit(1);
	}
	printf("%i\n", (*stack)->n);
}
