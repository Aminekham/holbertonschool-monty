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

/**
 * add - function add
 * @stack: stack
 * @line_number: line_number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *staackk = *stack;
	int sum = 0;

	if (!staackk || !staackk->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	sum = staackk->n + staackk->next->n;
	staackk->next->n = sum;
	pop(stack, line_number);
}

/**
 * is_digit - function test if the string is digit
 * Return: 0
 */
int is_digit(void)
{
	int l, c = 0, i = 0;

	if (value)
	{
		l = strlen(value);
		if (l == 1)
		{
			return (1);
		}
		if (value[0] == '-')
		{
			i++;
			c++;
		}
		for (; value[i]; i++)
		{
			if (value[i] >= '0' && value[i] <= '9')
			{
				c++;
			}
		}
		if (c == l)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * nop - function nop
 * @stack: stack_t
 * @line_number: line number
 */
void nop(__attribute__((unused)) stack_t **stack,
		 __attribute__((unused)) unsigned int line_number)
{
}
