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
    maze[i++] = (i / (size + 1)) % 2 + (((i / (size + 1)) % 4) / 2 + (i % (size + 1))) % 2 ? '#' : 'O';
    if (!((i + 1) % (size + 1)))
      maze[i++] = '\n';
  }
  maze[i] = '\0';
  return (maze);
}

void  random_move(unsigned int set_random, t_pos2i *next)
{
  int tree;

  set_random = random_in_range(set_random, RAND_MAX);
  tree = random_in_range(set_random, 4);
  if (tree < 2)
  {
    next->x = 0;
    next->y = (tree == 0) ? 1 : -1;
  }
  else
  {
    next->x = (tree == 2) ? 1 : -1;;
    next->y = 0;
  }
  printf("tree %d\n", tree);
}

int     is_move_safe(t_pos2i *pos, t_pos2i *next, char* maze, int size)
{
  int   x;
  int   y;

  x = pos->x + next->x;
  y = pos->y + next->y;
  if (x == 0 || x >= size - 1 || y == 0 || y >= size - 1)
  {
    maze[x + y * (size + 1)] = ' ';
    next->x = 0;
    next->y = 0;
    return (1);
  }
  if (maze[x + y * (size + 1)] == ' ' || maze[x + y * (size + 1)] == 'O')
    return (0);
  else if (maze[x + next->x + (y + next->y) * (size + 1)] == ' ')
    return (0);
  else if (maze[x + next->y + (y + next->x) * (size + 1)] == ' ')
    return (0);
  else if (maze[x - next->y + (y - next->x) * (size + 1)] == ' ')
    return (0);
  else
    return (1);
}

void    create_random_path(char *maze, int size)
{
  unsigned int set_random;
  t_pos2i   *pos;
  t_pos2i   *next;

  pos = new_pos2i(size / 2, size / 2);
  next = new_pos2i(0, 1);
  while (next->x || next->y)
  {
    maze[pos->x + pos->y * (size + 1)] = ' ';
    random_move((set_random = random_in_range(set_random, RAND_MAX)), next);
    while (!is_move_safe(pos, next, maze, size))
      random_move((set_random = random_in_range(set_random, RAND_MAX)), next);
    pos->x += next->x;
    pos->y += next->y;
  }
}

void    generate_maze(int size)
{
  char *maze;
  unsigned int set_random;
  int i = 10;

  printf("size %d\n", size);
  maze = fill_maze(size);
  create_random_path(maze, size);
  printf("%s", maze);
  // while (i--)
  // {
  //   set_random = random_in_range(set_random, RAND_MAX);
  //   printf("r %d\n", random_in_range(set_random, 4));
  // }
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