#include "monty.h"
int PUSH_VALUE;
/**
 * handle_opcode - to execute
 * @opcode: the opcode
 * @stack: the head
 * @line_number: number of lines
 */
void handle_opcode(char *opcode, stack_t **stack, int line_number)
{
	if (strcmp(opcode, "push") == 0)
		pushing(opcode, stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		_nop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		_swap(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop_stack(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		_pint(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		_add(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
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
/**
 * is_comm - is comment
 * @token: token
 * @line_count: num of lines
 * Return: integer
 */
int is_comm(char *token, int line_count)
{
	if (token == NULL || token[0] == '#')
	{
		line_count++;
		return (1);
	}
	return (-1);
}
/**
 * free_stack - free
 * @top: head
 */
void free_stack(stack_t *top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	while (top)
	{
		temp = top;
		top = top->next;
		free(temp);
	}

	free(top);
}
