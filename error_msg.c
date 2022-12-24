#include "monty.h"

/**
 * error_boss - function that call error functions
 * @opcode: the opcode
 * @line_number: line number
 */
void error_boss(char *opcode, unsigned int line_number)
{
	if (strcmp(opcode, "push") != 0 && line_number == 1)
	{
		push_not_found(opcode, line_number);
		return;
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint_error(opcode, line_number);
		return;
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop_error(opcode, line_number);
		return;
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap_error(opcode, line_number);
		return;
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add_error(opcode, line_number);
		return;
	}
	else
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
}

/**
 * pint_error - function that print error msg for pint
 * @opcode: the opcode
 * @line_number: line number
 */
void pint_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
}

/**
 * pop_error - function that print error msg for pop
 * @opcode: the opcode
 * @line_number: line number
 */
void pop_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
}

/**
 * swap_error - function that print error msg for swap
 * @opcode: the opcode
 * @line_number: line number
 */
void swap_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
}

/**
 * add_error - function that print error msg for add
 * @opcode: the opcode
 * @line_number: line number
 */
void add_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
}
