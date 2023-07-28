#include "monty.h"
/**
 * sub - add tzo nodes qnd pop the lqst
 * @stack: head
 * @line: line
 */
void sub(stack_t **stack, uint line)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n - (*stack)->next->n;
	pop_stack(stack, line);
	(*stack)->n = sum;
}