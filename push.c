#include "monty.h"

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
/**
 * _nop - no operqtion
 * @stack: head
 * @line: line
 */
void _nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
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
/**
 * _add - add tzo nodes qnd pop the lqst
 * @stack: head
 * @line: line
 */
void _add(stack_t **stack, uint line)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	pop_stack(stack, line);
}
