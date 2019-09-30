#include <stdio.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"
#define M_PI 3.14159265358979323846
/*
*   Maze generator take size in params :
*   Exemple : ./generate_maze 10
*
*   # ########
*   #    #   #
*   ####  ## #
*   #   #  # #
*   # #   #  #
*   # ####  ##
*   #     #  #
*   ### ## # #
*   #        #
*   ######## #
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

int    create_paths(char *maze, int size, char empty_block)
{
  unsigned int  set_random;
  t_pos2i       *path;
  int           i;

  if (!(path = malloc(sizeof(t_pos2i) * size * size)))
    throw_error("malloc() error --> path");
  path[0] = pos2i(1, 1);
  maze[path[0].x + path[0].y * (size + 1)] = empty_block;
  i = 0;
  while (i >= 0)
  {
    set_random = random_in_range(set_random, RAND_MAX);
    if (find_next_move(&(path[i]), maze, size, set_random))
      maze[path[++i].x + path[i].y * (size + 1)] = empty_block;
    else
      i--;
  }
  free(path);
}


t_pos2i pos2i(int x, int y)
{
  t_pos2i position;

  position.x = x;
  position.y = y;
  return (position);
}

int is_in_range(int number, int min, int max, int exclusive_range)
{
  if (number < min || number > max)
    return (0);
  else if (exclusive_range && (number == min || number == max))
    return (0);
  else
    return (1);
}

int is_pos2i_is_in_range(t_pos2i position, t_size min, t_size max,
  int exclusive_range)
{
  if (is_in_range(position.x, min.x, max.x, exclusive_range)
    && is_in_range(position.y, min.y, max.y, exclusive_range))
    return (1);
  else
    return (0);
}

int is_safe_move(t_pos2i position, int maze_size)
{
  return (is_pos2i_is_in_range(position, size(-1, -1),
    size(maze_size, maze_size), 1));
}


int is_end_block_safe(char *maze, int size, t_pos2i p, char empty_block)
{
  if (is_safe_move(pos2i(p.x + 1, p.y), size)
    && maze[(p.x + 1) + p.y * (size + 1)] == empty_block)
    return (1);
  else if (is_safe_move(pos2i(p.x - 1, p.y), size)
    && maze[(p.x - 1) + p.y * (size + 1)] == empty_block)
    return (1);
  else if (is_safe_move(pos2i(p.x, p.y + 1), size)
    && maze[p.x + (p.y + 1) * (size + 1)] == empty_block)
    return (1);
  else if (is_safe_move(pos2i(p.x, p.y - 1), size)
    && maze[p.x + (p.y - 1) * (size + 1)] == empty_block)
    return (1);
  else
    return (0);
}

void  create_end_block(char *maze, int size, char empty_block, char end_block)
{
  int      r;
  int      random_side;
  t_pos2i  p;
  
  p = pos2i(0, 0);
  while (!is_end_block_safe(maze, size, p, empty_block))
  {
    random_side = (r = random_in_range(r, RAND_MAX)) % 2;
    if (random_side)
    {
      p.x = ((r = random_in_range(r, RAND_MAX)) % 2) * (size -1);
      p.y = (r = random_in_range(r, RAND_MAX)) % size;
    }
    else
    {
      p.x = (r = random_in_range(r, RAND_MAX)) % size;
      p.y = ((r = random_in_range(r, RAND_MAX)) % 2) * (size -1);
    }
  }
  maze[p.x + p.y * (size + 1)] = end_block;
}

t_pos2i find_spawn_safe_coor(char *maze, int size, char empty_block)
{
  t_pos2i p;
  t_pos2i shift;
  int     rayon;
  int     sign;
  int     hit_empty_block;

  hit_empty_block = 0;
  rayon = 1;
  p = pos2i(size / 2, size / 2);
  shift = pos2i(0,0);
  sign = 1;
  while (!hit_empty_block && is_safe_move(p, size))
  {
    shift = pos2i(0, 0);
    while (shift.x * sign < rayon && is_safe_move(p, size))
    {
      if (maze[p.x + p.y * (size + 1)] == empty_block)
        return (p);
      shift.x += sign;
      p.x += sign;
    }
    while (shift.y * sign < rayon && is_safe_move(p, size))
    {
      if (maze[p.x + p.y * (size + 1)] == empty_block)
        return (p);
      shift.y += sign;
      p.y += sign;
    }
    sign *= -1;
    rayon++;
  }
}

void  export_textures(FILE *fp)
{
  fprintf(fp, "\n-textures\n");
  fprintf(fp, "maze: ./resources/textures/maze.png\n");
  fprintf(fp, "end: ./resources/textures/end.jpg\n");
}

void  export_blocks(FILE *fp)
{
  fprintf(fp, "\n-blocks\n");
  fprintf(fp, "a: %s %s %s %s\n", "maze", "maze", "maze", "maze");
  fprintf(fp, "E: %s %s %s %s\n", "end", "end", "end", "end");
}

void  export_size(FILE *fp, int size)
{
  fprintf(fp, "\n-size\n");
  fprintf(fp, "height: %d\n", size);
  fprintf(fp, "width: %d\n", size);
}

void  export_map(FILE *fp, char **maze)
{
  int i;

  i = 0;
  fprintf(fp, "\n-map\n");
  while (maze && maze[i])
  {
    fprintf(fp, ": ");
    fprintf(fp, "%s\n", maze[i]);
    i++;
  }
}

void  export_player(FILE *fp, t_pos2i spawn)
{
  int     set_random;
  double  direction;

  set_random = random_in_range(set_random, RAND_MAX);
  direction = (double)(set_random % 360) * M_PI / 180.0;
  fprintf(fp, "\n-player\n");
  fprintf(fp, "spawn: %f %f\n", (float)spawn.x + 0.5, (float)spawn.y + 0.5);
  // fprintf(fp, "direction: %f\n", direction);
}

void    export_maze(char **maze, int size, t_pos2i spawn)
{
  FILE  *fp;

  if (!(fp = fopen("maze_test.wolf", "w")))
    return ;
  export_textures(fp);
  export_blocks(fp);
  export_size(fp, size);
  export_map(fp, maze);
  export_player(fp, spawn);
}

void    generate_maze(int size)
{
  char *maze;
  char empty_block = ' ';
  char block = 'a';
  char end_block = 'E';
  t_pos2i spawn;

  maze = fill_maze(size, block);
  create_paths(maze, size, empty_block);
  create_end_block(maze, size, empty_block, end_block);
  spawn = find_spawn_safe_coor(maze, size, ' ');
  export_maze(ft_strsplit(maze, '\n'), size, spawn);
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
