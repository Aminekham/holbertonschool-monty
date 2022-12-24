#include "monty.h"
char *value;

/**
 * push - function that push to the stack
 * @stack:       stack
 * @line_number: Line Number
 */
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

/**
 * push_not_found - function that print error msg if push not found
 * @opcode: the opcode
 * @line_number: line number
 */
void push_not_found(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
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
