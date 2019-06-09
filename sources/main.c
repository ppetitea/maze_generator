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

char *fill_maze(int size, char c)
{
  char *maze;
  int   string_length;
  int  i;

  string_length = (size + 1) * size;
  if (!(maze = malloc(sizeof(char) * (string_length + 1))))
    throw_error("malloc() error --> maze");
  i = 0;
  while (i < string_length)
  {
    maze[i++] = c;
    if (!((i + 1) % (size + 1)))
      maze[i++] = '\n';
  }
  maze[i] = '\0';
  return (maze);
}

int     is_move_safe(t_pos2i pos, t_pos2i next, char* maze, int size)
{
  int   x;
  int   y;

  x = pos.x + next.x;
  y = pos.y + next.y;
  if (x == 0 || x >= size - 1 || y == 0 || y >= size - 1)
    return (0);
  if (maze[x + y * (size + 1)] == ' ')
    return (0);
  else if (maze[x + next.x + (y + next.y) * (size + 1)] == ' ')
    return (0);
  else if (maze[x + next.y + (y + next.x) * (size + 1)] == ' ')
    return (0);
  else if (maze[x - next.y + (y - next.x) * (size + 1)] == ' ')
    return (0);
  else
    return (1);
}

int   find_next_move(t_pos2i *path, char *maze, int size, unsigned int set_random)
{
  t_pos2i next[3];
  int     move_nbr;

  move_nbr = 0;
  if (is_move_safe(*path, pos2i(1, 0), maze, size))
    next[move_nbr++] = pos2i(1, 0);
  if (is_move_safe(*path, pos2i(-1, 0), maze, size))
    next[move_nbr++] = pos2i(-1, 0);
  if (is_move_safe(*path, pos2i(0, 1), maze, size))
    next[move_nbr++] = pos2i(0, 1);
  if (is_move_safe(*path, pos2i(0, -1), maze, size))
    next[move_nbr++] = pos2i(0, -1);
  if (!move_nbr)
    return (0);
  set_random = random_in_range(set_random, RAND_MAX);
  move_nbr = random_in_range(set_random, move_nbr);
  path[1].x = path[0].x + next[move_nbr].x;
  path[1].y = path[0].y + next[move_nbr].y;
  return (1);
} 

int    create_paths(char *maze, int size)
{
  unsigned int  set_random;
  t_pos2i       *path;
  int           i;

  if (!(path = malloc(sizeof(t_pos2i) * size * size)))
    throw_error("malloc() error --> path");
  path[0] = pos2i(1, 1);
  maze[path[0].x + path[0].y * (size + 1)] = ' ';
  i = 0;
  while (i >= 0)
  {
    set_random = random_in_range(set_random, RAND_MAX);
    if (find_next_move(&(path[i]), maze, size, set_random))
      maze[path[++i].x + path[i].y * (size + 1)] = ' ';
    else
      i--;
  }
  free(path);
}

void    open_maze(char *maze, int size)
{
  maze[1] = ' ';
  maze[size - 2 + (size - 1) * (size + 1)] = ' ';
  maze[size - 2 + (size - 2) * (size + 1)] = ' ';
}

void    generate_maze(int size)
{
  char *maze;

  maze = fill_maze(size, '#');
  create_paths(maze, size);
  open_maze(maze, size);
  printf("%s", maze);
}

int main(int ac, char **av)
{
    int size;

    if (size = is_input_is_valid_integer(ac, av))
        generate_maze(size);
    else
        ft_putstr("usage: ./generate_maze size\n\tsize: [6 - 100]");
    return (0);
}