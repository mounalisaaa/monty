#include "monty.h"

int PUSH_VALUE;

void handle_opcode(char *opcode, stack_t **stack, int line_number)
{
	int n;

	if (strcmp(opcode, "push") == 0)
	{
		opcode = strtok(NULL, " \t\n");
		if (!opcode)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		n = atoi(opcode);
		if (!n && strcmp(opcode, "0") != 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		PUSH_VALUE = n;
		push(stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
