#include "monty.h"
char *global_value = 0;
/**
* main - Stacks, Queues - LIFO, FIFO
* @argc: counter
* @argv: arguments
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *op = NULL;
	unsigned int line = 0;
	char *buff = NULL, *token = NULL;
	stack_t *h = NULL;
	size_t buff_size = 0;

	if (argc != 2)
	{
		printf("acá");
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	op = fopen(argv[1], "r");
	if (op == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &buff_size, op) != -1)
	{
		line++;
		global_value = 0;
		token = strtok(buff, "\n\t\a\r ");
		if (!token)
			continue;

		global_value = strtok(NULL, "\n\t\a\r ");
		if (get_op_func(token))
		{
			get_op_func(token)(&h, line);
		}
		else
		{
			free_list(&h);
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, token);
			free(buff);
			fclose(op);
			exit(EXIT_FAILURE);
		}
	}
	free_list(&h);
	free(buff);
	fclose(op);
	return (0);
}
