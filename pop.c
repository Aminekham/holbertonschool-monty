#include "monty.h"

/**
 * pop - function pop
 * @stack: stack
 * @line_number: line_number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		free(*stack);
		node = node->next;
		*stack = node;
	}
}
