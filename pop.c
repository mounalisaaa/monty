#include "monty.h"
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
