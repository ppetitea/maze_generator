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

void  random_move(t_pos2i *next)
{
  int axis;

  axis = random_range(2);
  if (axis)
  {
    next->x = 0;
    next->y = (random_range(2) ? 1 : -1);
  }
  else
  {
    next->x = (random_range(2) ? 1 : -1);
    next->y = 0;
  }
}

void    create_random_path(char *maze, int size)
{
  t_pos2i   *pos;
  t_pos2i   *next;

  pos = new_pos2i(1, 0);
  next = new_pos2i(0, 1);

  while (next->x || next->y)
  {
    maze[pos->x + pos->y * (size + 1)] = 'O';
    while (!is_safe(pos, next, maze, size))
      random_move(next);
    pos->x += next->x;
    pos->y += next->y;
  }
}

void    generate_maze(int size)
{
  char *maze;
  
  printf("size %d\n", size);
  maze = fill_maze(size);
  create_random_path(maze, size);
  printf("%s", maze);
  //add_random_dead_ends(maze, size);
}

int main(int ac, char **av)
{
    int size;

    size = 0;
    if (size = is_input_is_valid_integer(ac, av))
        generate_maze(size);
    else
        ft_putstr("usage: ./generate_maze size\n\tsize = [6 - 100]");
    return (0);
}