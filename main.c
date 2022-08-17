#include "monty.h"
/**
* main - Stacks, Queues - LIFO, FIFO
* @argc: counter
* @argv: arguments
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	int op, pusher = 0;
	ssize_t re;
	unsigned int line = 1;
	char *buff, *token;
	stack_t *h = NULL;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 10000);
	if (!buff)
		return (0);
	re = read(op, buff, 10000);
	if (re == -1)
	{
		free(buff);
		close(op);
		exit(EXIT_FAILURE);
	}
	token = strtok(buff, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (pusher == 1)
		{
			_push(&h, line, token);
			pusher = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			pusher = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op_func(token) != 0)
			{
				get_op_func(token)(&h, line);
			}
			else
			{
				free_list(&h);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_list(&h);
	free(buff);
	close(op);
	return (0);
}
