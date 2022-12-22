#include "monty.h"
/**
 * 
 * 
*/
void push(stack_t **stack, unsigned int line_number, FILE *f)
{
    char c;
    stack_t *head = NULL;

    if (line_number == 1)
    { 
        c = getc(f);
        (*stack)->n = atoi(&c);
        head = *stack;
    }
    else
    {
        c = getc(f);
        (*stack)->n = atoi(&c);
        (*stack)->prev = head;
        head->next = *stack;
        head = *stack;
    }
}