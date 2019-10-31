/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dig_maze.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:35:43 by pp                #+#    #+#             */
/*   Updated: 2019/10/31 19:35:44 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/generate_maze.h"
#include <stdlib.h>

void    get_next_moves(t_vec2i move, t_vec2i *moves)
{
    unsigned int set_random;
    
    moves[0].x = move.x;
    moves[0].y = move.y;
    moves[1].x = -move.y;
    moves[1].y = -move.x;
    moves[2].x = move.y;
    moves[2].y = move.x;
    set_random = random_in_range(set_random, RAND_MAX);
    sort_random(moves, 3, set_random);
}

t_bool is_belong_map(t_pos2i pos, int size)
{
    if (pos.x < 0 || pos.x >= size)
        return (FALSE);
    if (pos.y < 0 || pos.y >= size)
        return (FALSE);
    return (TRUE);
}

t_bool  is_safe_move(t_maze *maze, t_pos2i pos, t_vec2i move)
{
    t_pos2i new_pos;

    if (!is_belong_map(pos, maze->size))
        return (FALSE);
    new_pos = pos2i(pos.x + move.x, pos.y + move.y);
    if (!is_belong_map(new_pos, maze->size) ||
        maze->map[new_pos.x + new_pos.y * maze->size] == maze->empty_block)
        return (FALSE);
    new_pos = pos2i(pos.x - move.y, pos.y - move.x);
    if (!is_belong_map(new_pos, maze->size) ||
        maze->map[new_pos.x + new_pos.y * maze->size] == maze->empty_block)
        return (FALSE);
    new_pos = pos2i(pos.x + move.y, pos.y + move.x);
    if (!is_belong_map(new_pos, maze->size) ||
        maze->map[new_pos.x + new_pos.y * maze->size] == maze->empty_block)
        return (FALSE);
    return (TRUE);
}

int    dig_maze(t_maze *maze, t_pos2i pos, t_vec2i last_move)
{
    t_vec2i next_moves[3];
    t_pos2i new_pos;
    int i;

    maze->map[pos.x + pos.y * maze->size] = maze->empty_block; 
    get_next_moves(last_move, (t_vec2i*)next_moves);
    i = 0;
    while (i < 3)
    {
        new_pos = pos2i(pos.x + next_moves[i].x , pos.y + next_moves[i].y);
        if (is_safe_move(maze, new_pos, next_moves[i]))
        {
            if (!dig_maze(maze, new_pos, next_moves[i]))
                return (ERROR);
        }
        i++;
    }
    return (OK);
}