#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: head
 * @line: line
 */
void _swap(stack_t **stack, unsigned int line)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
