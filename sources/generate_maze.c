/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_maze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:44:22 by pp                #+#    #+#             */
/*   Updated: 2019/11/01 18:22:29 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/libft.h"
#include "../includes/generate_maze.h"


t_bool is_belong_i(int number, int min, int max)
{
    return (number >= min && number <= max ? TRUE : FALSE);
}

t_maze *new_maze(int size, char full_block, char empty_block, char end_block)
{
    t_maze *new_maze;

    if (!(new_maze = (t_maze*)malloc(sizeof(t_maze))))
        return (ERROR);
    if (!(new_maze->map = (char*)malloc(sizeof(char) * size * size)))
        return (ERROR);
    new_maze->full_block = full_block;
    new_maze->empty_block = empty_block;
    new_maze->end_block = end_block;
    new_maze->size = size;
    return (new_maze);
}

void    fill_maze(t_maze *maze)
{
    int y;
    int x;

    y = 0;
    while (y < maze->size)
    {
        x = 0;
        while (x < maze->size)
        {
            maze->map[x + y * maze->size] = maze->full_block;
            x++;
        }
        y++;
    }
}

int    generate_maze(int size)
{
    t_maze *maze;

    if (!is_belong_i(size, 6, 10000))
        return (ERROR);
    maze = new_maze(size, 'a', ' ', 'E');
    fill_maze(maze);
    if (!dig_maze(maze, pos2i(1, 1), vec2i(1, 0)))
        return (ERROR);
    create_end_block(maze);
    maze->spawn = get_spawn_position(maze, 1, 2);
    maze->map[maze->spawn.x + maze->spawn.y * maze->size] = 'S'; //died soon
    show_maze(maze);
    return (OK);
}

int main(int ac, char **av)
{
    int size;

    size = ft_atoi(av[1]);
    if (size <= 5 || size > 10000)
        ft_putstr("usage: ./generate_maze size\n\tsize: [6 - 10000]");
    else
        generate_maze(size);
    return (0);
}
