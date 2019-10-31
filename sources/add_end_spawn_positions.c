/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_end_spawn_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:35:20 by pp                #+#    #+#             */
/*   Updated: 2019/10/31 19:35:21 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/generate_maze.h"
#include "../libft/includes/libft.h"


t_bool  is_safe_end_block(t_maze *maze, t_pos2i pos)
{
    int size;

    size = maze->size;
    if (!is_belong_map(pos, maze->size))
        return (FALSE);
    if (pos.x == 0  && maze->map[1 + pos.y * size] != maze->empty_block)
        return (FALSE);
    if (pos.x == (size - 1) && maze->map[(size - 2) + pos.y * size] != maze->empty_block)
        return (FALSE);
    if (pos.y == 0  && maze->map[pos.x + 1 * size] != maze->empty_block)
        return (FALSE);
    if (pos.y == (size - 1) && maze->map[pos.x + (size - 2) * size] != maze->empty_block)
        return (FALSE);
    return (TRUE);
}

void    create_end_block(t_maze *maze)
{
    int r;
    int random_side;
    t_pos2i p;

    p = pos2i(0, 0);
    while (!is_safe_end_block(maze, p))
    {
        random_side = (r = random_in_range(r, RAND_MAX)) % 2;
        if (random_side)
        {
            p.x = ((r = random_in_range(r, RAND_MAX)) % 2) * (maze->size -1);
            p.y = (r = random_in_range(r, RAND_MAX)) % maze->size;
        }
        else
        {
            p.x = (r = random_in_range(r, RAND_MAX)) % maze->size;
            p.y = ((r = random_in_range(r, RAND_MAX)) % 2) * (maze->size -1);
        }
    }
    maze->map[p.x + p.y * maze->size] = maze->end_block;
}

t_pos2i    get_spawn_position(t_maze *maze, int m, int radius)
{
    t_pos2i p;
    int i;

    p = pos2i(maze->size / 2, maze->size / 2);
    while (radius < maze->size)
    {
        i = 0;
        while (i < radius)
        {
            if (maze->map[p.x - m + i + (p.y - m) * maze->size] == maze->empty_block)
                return (pos2i(p.x - m + i, p.y - m));
            if (maze->map[p.x + m + (p.y - m + i) * maze->size] == maze->empty_block)
                return (pos2i(p.x + m, p.y - m + i));
            if (maze->map[p.x + m - i + (p.y + m) * maze->size] == maze->empty_block)
                return (pos2i(p.x + m - i, p.y + m));
            if (maze->map[p.x - m + (p.y + m - i) * maze->size] == maze->empty_block)
                return (pos2i(p.x - m, p.y + m - i));
            i++;
        }
        radius += 2;
        m++;
    }
    return p;
}