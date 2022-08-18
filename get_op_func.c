#include "monty.h"

/**
* get_op_func - check code
* @s: char
* Return: 0
*/
void (*get_op_func(char *s))(stack_t **stack, unsigned int h)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", _pall},
		{"push", _push},
		{NULL, NULL}
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}
	return (NULL);
}
