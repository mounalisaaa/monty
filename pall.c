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
/**
 * _pint - check code
 * @stack: ptr to stack
 * @line_num: the line
 */

void _pint(stack_t **stack, unsigned int line_num)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
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
