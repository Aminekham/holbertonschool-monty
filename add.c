#include "monty.h"

/**
 * add - function add
 * @stack: stack
 * @line_number: line_number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *staackk = *stack;
	int x;

	if (staackk == NULL)
	{
		fprintf(stderr, "L%d: can't add, staackk too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	x = staackk->n + staackk->next->n;
	staackk->next->n = x;
	staackk = staackk->next;
}
