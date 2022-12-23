#include "monty.h"

/**
 * swap - function swap between two stacks
 * @stack: stack
 * @line_number: line_number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *swap;
	int s;

	if (node->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		swap = node;
		node = node->next;
		s = swap->n;
		swap->n = node->n;
		node->n = s;
	}
}
