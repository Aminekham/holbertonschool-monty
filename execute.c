#include "monty.h"

/**
 * execute - function that execute a line
 * @line:        line to be executed
 * @stack:       stack
 * @line_number: Line Number
 */

void execute(char *line, stack_t **stack, unsigned int line_number)
{
	int i;
	char *opcode;

	if (strcmp(line, "") == 0)
	{
		free(line);
		free(stack);
		return;
	}
	opcode = strtok(line, " \n\t\r");
	if (opcode == NULL)
		return;
	if (strcmp(opcode, "push") != 0 && line_number == 1)
	{
		error_boss(opcode, line_number);
		exit(EXIT_FAILURE);
	}
	value = strtok(NULL, " \n\t\r");
	i = is_digit();
	if (((value == NULL) || (i == 0)) && strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	get_opcode(line, opcode, stack, line_number);
}
