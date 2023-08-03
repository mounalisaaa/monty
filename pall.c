#include "monty.h"

/**
 * pall - "print all" elements of stack starting from the top
 * @stack: the head (top)
 * @line_number: (void)
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
