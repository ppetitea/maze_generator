/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_maze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:35:05 by pp                #+#    #+#             */
/*   Updated: 2019/10/31 19:36:38 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/generate_maze.h"
#include <stdio.h>

void    show_maze(t_maze *maze)
{
    int y;
    int x;

    y = 0;
    while (y < maze->size)
    {
        x = 0;
        while (x < maze->size)
        {
            printf("%c", maze->map[x + y * maze->size]);
            x++;
        }
        printf("\n");
        y++;
    }
}