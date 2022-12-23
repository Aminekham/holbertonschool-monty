#include "monty.h"

int main( __attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
	size_t i = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	char *filename;
	FILE *fp;
	char *line = NULL;
	unsigned int line_number = 0;

	filename = "bytecodes/00.m";
	fp = fopen(filename, "r");
	if ((fp == NULL))
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (read > 0)
	{
		read = getline(&line, &i, fp);
		line_number++;

		if (read > 0)
		{
			execute(line, &stack, line_number);
		}
	}
	free(line);
	fclose(fp);

	return (0);
}