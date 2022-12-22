#include "monty.h"
/**
 * 
 * 
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number, __attribute__((unused)) FILE *f)
{
    while(*stack)
    {
        printf("%d", (*stack)->n);
        *stack = (*stack)->next;
    }
}