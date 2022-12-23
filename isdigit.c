#include "monty.h"
/**
 *
 *
 */
int is_digit(void)
{
    int l, c = 0, i = 0;

    if (value)
    {
        l = strlen(value);
        if (l == 1)
        {
            return (1);
        }
        if (value[0] == '-')
        {
            i++;
            c++;
        }
        for (; value[i]; i++)
        {
            if (value[i] > '0' && value[i] < '9')
            {
                c++;
            }
        }
        if (c == l)
        {
            return (1);
        }
    }
    return (0);
}