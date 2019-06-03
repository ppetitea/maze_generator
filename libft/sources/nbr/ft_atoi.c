#include "../../includes/str.h"
#include <stdio.h>
int ft_atoi(char *string)
{
    int number;
    int sign;

    number = 0;
    if (!string)
        return (0);
    while (*string && ft_isspace(*string))
        string++;
    sign = (*string == '-') ? -1 : 1;
    if (*string == '-' || *string == '+')
        string++;
    while (*string)
    {
        if (!ft_isnumber(*string))
            return (0);
        number *= 10;
        number += *string - '0';
        string++;
    }
    return (sign * number);
}