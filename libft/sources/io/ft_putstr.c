#include <unistd.h>
#include "../../includes/str.h"

void    ft_putstr(char *string)
{
    int string_length;

    if (string != 0)
    {
        string_length = ft_strlen(string);
        write(1, string, string_length);
        write(1, "\n", 1);
    }
}