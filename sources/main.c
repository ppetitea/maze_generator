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

void fill_maze(char *maze, int size)
{
  int  i;
  
  i = 0;
  if (!maze)
    return ;
  while (maze[i] && i < (size + 1) * size)
  {
    if (i && !(i % (size + 1)))
      maze[i] = '\n';
    maze[i] = '#';
    i++;
  }
}

void    generate_maze(int size)
{
  char *maze;
  
  if (!(maze = malloc(sizeof(char) * (size + 1) * size)))
    return ;
  fill_maze(maze, size);
  create_random_path(maze, size);
  add_random_dead_ends(maze, size);
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