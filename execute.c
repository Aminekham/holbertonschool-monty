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

    if (strcmp(line, "") == 0)
    {
        return;
    }
    opcode = strtok(line, " \n\t\r");
    value = strtok(NULL, " \n\t\r");
    if (value == NULL && strcmp(opcode, "push") == 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
            fprintf(stderr, "L%d: unknown instruction push\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
}