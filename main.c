#include "monty.h"

int main(int argc, char *argv[])
{
	size_t i = 0, k;
	stack_t *stack = NULL;
	char *filename;
	FILE *fp;
	char *line, *opcode;
	int line_number = 1;
	instruction_t table[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	fp = fopen(filename, "r");
	if ((fp == NULL))
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((getline(&line, &i, fp) != -1))
	{
		line_number++;

		opcode = strtok(line, " \n\t\r");
		value = strtok(NULL, " \n\t\r");

		while (table[k].opcode)
		{
			if (strcmp(opcode, table[k].opcode) == 0)
			{
				table[k].f(&stack, line_number);
			}
			k++;
		}

		if (!table[k].opcode)
		{
			fprintf(stderr, "L%d: unknown instruction pushe***\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	fclose(fp);

	return (0);
}