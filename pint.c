#include "monty.h"

/**
 * pint - function pint
 * @stack: stack
 * @line_number: line_number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
}
