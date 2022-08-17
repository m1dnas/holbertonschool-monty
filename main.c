#include "monty.h"

int main(int argc, char *argv[])
{
	int op, re, pu = 0;
	unsigned int line = 1;
	char **buff, *token;
	stack_t *h;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op = open(argv[1], O_RDONLY);

	if (op == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 1024);

	if (!buff)
		return (0);

	re = read(op, buff, 1024);
	if (re == -1)
	{
		free(buff);
		close(op);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		if (pu == 1)
		{
			_push(&h, line, token);
			pu = 0;
			token = strtok(NULL, "\t\n\r\a");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			pu = 1;
			token = strtok(NULL, " \t\n\r\a");
			continue;
		}
	}
	return (0);
}
