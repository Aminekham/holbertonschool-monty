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
    else
    {
        pint_error(opcode, line_number);
        return;
    }
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
