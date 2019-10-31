/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_maze.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:22:46 by pp                #+#    #+#             */
/*   Updated: 2019/10/31 19:47:37 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_MAZE_H

    #include "../libft/includes/maths.h"
    #include "../libft/includes/types.h"
        
    typedef struct      s_maze
    {
        char    *map;
        int     size;
        char    full_block;
        char    empty_block;
        char    end_block;
        t_pos2i spawn;
    }                   t_maze; 

    int         dig_maze(t_maze *maze, t_pos2i pos, t_vec2i last_move);
    void        create_end_block(t_maze *maze);
    t_pos2i     get_spawn_position(t_maze *maze, int m, int radius);
    void        show_maze(t_maze *maze);
    t_bool      is_belong_map(t_pos2i pos, int size);

#endif