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
		if (check_int(opcode) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		n = atoi(opcode);
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
/**
 * check_int - check if a string is consist of integers only
 * @str: the string
 * Return: return 0 or 1
 */
int check_int(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}