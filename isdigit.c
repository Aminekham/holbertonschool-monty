#include "monty.h"
#include <ctype.h>
/**
 * 
 * 
*/
int is_digit(char *value)
{
    int l, c = 0 , r;

    l = strlen(value);
    if (*value == '-')
    {
        for (int i = 0; i < l - 1; i++)
        {
            value[i] = value[i + 1];
        }
    }
    for (int i = 0; i < l; i++)
    {
        r = isdigit(*value);
        if (r == 0)
        {
            c = c;
        }
        else
        {
            c++;
        }
        value++;
    }
    if (c == l)
    {
        return(1);
    }
    return(0);
}