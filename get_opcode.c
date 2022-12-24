#include "monty.h"

/**
 * get_opcode - function that call the function needed
 * @line:    line to be executed
 * @opcode:  the opcode
 * @stack:   stack
 * @line_number: line number
 */

void get_opcode(char *line, char *opcode,
				stack_t **stack, unsigned int line_number)
{
	int k = 0;
	instruction_t table[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}};

	while (table[k].opcode)
	{
		if (strcmp(opcode, table[k].opcode) == 0)
		{
			table[k].f(stack, line_number);
			return;
		}
		k++;
		if (table[k].opcode == NULL)
		{
			error_boss(opcode, line_number);
			free(line);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
}
