#include "monty.h"

/***/

void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));
	int x;

	x = atoi(value);
	node->n = x;
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}

/***/

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node = *stack;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
