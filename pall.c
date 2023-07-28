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
/**
 * pop_stack - removes the top element of the stack.
 * @stack: head
 * @line: line
 */
void pop_stack(stack_t **stack, uint line)
{
	stack_t *tmp;

	tmp = *stack;
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = tmp->next;
	free(*stack);
	*stack = tmp;
}
