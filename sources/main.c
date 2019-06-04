#include <stdio.h>
#include <stdlib.h>
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

char *fill_maze(int size)
{
  char *maze;
  int   string_length;
  int  i;
  
  string_length = (size + 1) * size;
  if (!(maze = malloc(sizeof(char) * (string_length + 1))))
    return (0);
  i = 0;
  while (i < string_length)
  {
    maze[i++] = '#';
    if (!((i + 1) % (size + 1)))
      maze[i++] = '\n';
  }
  maze[i] = '\0';
  return (maze);
}

void    generate_maze(int size)
{
  char *maze;
  
  printf("size %d\n", size);
  maze = fill_maze(size);
  printf("%s\n", maze);
  //create_random_path(maze, size);
  //add_random_dead_ends(maze, size);
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