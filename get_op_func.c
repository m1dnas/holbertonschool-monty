#include "monty.h"

/**
* get_op_func - check code
* @s: char
* Return: 0
*/
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pall", _pall},
/**		{"pint", _pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},*/
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (instruction_s[i].f != NULL)
	{
		if (*(instruction_s[i].opcode) == s[0])
		{
			return (instruction_s[i].f);
		}
		i++;
	}
	return (NULL);
}
