#include "monty.h"

/**
 * pushing - push helper
 * @opcode: the opcode
 * @stack: the head
 * @line_number: number of lines
 */
void pushing(char *opcode, stack_t **stack, int line_number)
{
	int n;

	opcode = strtok(NULL, " \t\n");
	if (!opcode || check_int(opcode) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(opcode);
	PUSH_VALUE = n;
	push(stack, line_number);
}

/**
 * push - add node at the beg of stack
 * @stack: head of the stack
 * @line_number: void
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = PUSH_VALUE;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
