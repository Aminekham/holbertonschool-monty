#include "monty.h"

/**
 * push - function that push to the stack
 * @stack:       stack
 * @line_number: Line Number
 */

char *value;
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

/**
 * pall - function that prints all the values on the stack
 *					starting from the top of the stack.
 * @stack:       stack
 * @line_number: Line Number
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node = *stack;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * free_stack - function that free the stack
 * @stack: stack
 */
void free_stack(stack_t *stack)
{
	stack_t *a;

	while (stack)
	{
		a = stack;
		stack = stack->next;
		free(a);
	}
}
