#include "monty.h"

/**
 * execute - function that execute a line
 * @line:        line to be executed
 * @stack:       stack
 * @line_number: Line Number
 */

void execute(char *line, stack_t **stack, unsigned int line_number)
{
	int k = 0, i;
	char *opcode;
	instruction_t table[] = {
		{"pall", pall}, {"push", push}, {"pint", pint}, {"pop", pop}, {NULL, NULL}};

	if (strcmp(line, "") == 0)
	{
		free(line);
		free(stack);
		return;
	}
	opcode = strtok(line, " \n\t\r");
	if (opcode == NULL)
		return;
	value = strtok(NULL, " \n\t\r");
	i = is_digit();
	if (((value == NULL) || (i == 0)) && strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
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
			fprintf(stderr, "L%d: unknown instruction pushe\n", line_number);
			free(line);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
}
