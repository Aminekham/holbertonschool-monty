#include "monty.h"

/***/

void execute(__attribute__((unused)) char *line, stack_t **stack, unsigned int line_number)
{
    int k = 0;
    char *opcode = malloc(1024 * sizeof(char));
    instruction_t table[] = {
        {"pall", pall},
        {"push", push},
        {NULL, NULL}};

    opcode = strtok(line, " \n\t\r");
    value = strtok(NULL, " \n\t\r");
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
            fprintf(stderr, "L%d: unknown instruction pushe***\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
}