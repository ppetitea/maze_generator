#include "../../includes/io.h"

void    init_array(int *array, int init_number)
{
    if (array)
    {
        while (*array)
            *array++ = init_number;
    }
    else
        ft_putstr("Error - Array is a null pointer !");
}