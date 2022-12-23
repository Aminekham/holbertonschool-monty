#include "monty.h"

int main(int argc, char *argv[])
{
	size_t k = 0;
	stack_t *stack = NULL;
	char *filename;
	FILE *fp;
	char *line = malloc(sizeof(char) * 1024), *opcode;
	int line_number = 0;

	instruction_t table[] = {
		{"pall", pall},
		{"push", push},
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

	while ((fgets(line, 100, fp) != NULL) && line_number++)
	{
		if (strlen(line) == 1)
		{
			line_number++;
			continue;
		}
		else
		{
			opcode = strtok(line, " \n\t\r");
			value = strtok(NULL, " \n\t\r");

			while (table[k].opcode && opcode)
			{
				if (strcmp(opcode, table[k].opcode) == 0)
				{
					table[k].f(&stack, line_number);
					return (0);
				}

				k++;

				if (table[k].opcode == NULL)
				{
					fprintf(stderr, "L%d: unknown instruction pushe***\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
			k = 0;
			line = NULL;
		}
		line_number++;
	}
	fclose(fp);

	return (0);
}