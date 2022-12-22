#include "monty.h"
/**
 *
 *
 *
 */
int main(int argc, char *argv[])
{
	FILE *f; 
	int i = 1;
	char *s = malloc (1024 * sizeof(char));
	stack_t *data;
	instruction_t inst[] = {
		{"push ", push},
		{"pall ", pall},
		{NULL, NULL},
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	while (*s)
	{
		*s = fgetc(f);
		if (*s == ' ')
		{
			inst->opcode = s;
			if (strcmp(s, "push "))
			{
				inst[0].f(&data, i, f);
			}
			else if (strcmp(s, "pall "))
			{
				inst[1].f(&data, i, f);
			}
		}
		if (*s == '\n')
		{
			i++;
			s = "";
		}
		s++;
	}
	fclose(f);
	return(0);
}