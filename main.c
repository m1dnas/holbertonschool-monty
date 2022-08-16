#include "main.h"

int main(int argc, char *argv[])
{
	char *input = NULL;
	char *buf[1024];
	char *tok;
	int num;

	if (num != atoi(argv[2]))
	{
		dprintf("L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}
