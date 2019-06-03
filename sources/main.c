#include <stdio.h>
#include "../libft/includes/libft.h"

/*
*   Maze generator take size in params :
*   Exemple : "./generate_maze 42" will generate maze with size 42 by 42
*/

int is_input_is_valid_integer(int ac, char **av)
{
    int size;

    size = 0;
    if (ac != 2 || !av || !*av)
        return (0);
    size = ft_atoi(av[1]);
    if (size <= 5 || size > 100)
        return (0);
    return (size);
}

void    generate_maze(int size)
{

}

int main(int ac, char **av)
{
    int size;

    size = 0;
    if (size = is_input_is_valid_integer(ac, av))
        generate_maze(size);
    else
        ft_putstr("usage: ./generate_maze size\n\tsize = [4 - 100]");
    return (0);
}