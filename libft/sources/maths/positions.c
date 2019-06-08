#include <stdlib.h>
#include "../../includes/maths.h"

/*
** integer positions
*/

t_pos2i    *new_pos2i(int x, int y)
{
    t_pos2i *pos;

    if (!(pos = malloc(sizeof(t_pos2i))))
        return (NULL);
    pos->x = x;
    pos->y = y;
    return (pos);
}

t_pos2i    *pos2i(t_pos2i *pos, int x, int y)
{
    if (pos)
    {
        pos->x = x;
        pos->y = y;
        return (pos);
    }
    else
        return (new_pos2i(x, y));
}

t_pos2i    *pos2i_add(t_pos2i *pos1, t_pos2i *pos2)
{
    t_pos2i *pos;

    if (!pos1 || !pos2)
        return (NULL);
    if (!(pos = malloc(sizeof(t_pos2i))))
        return (NULL);
    pos->x = pos1->x + pos2->x;
    pos->y = pos1->y + pos2->y;
    return (pos);
}

int         are_pos2i_equal(t_pos2i *pos1, t_pos2i *pos2)
{
    if (!pos1 || !pos2)
        return (0);
    if (pos1->x == pos2->x && pos1->y == pos2->y)
        return (1);
    else
        return (0);    
}

t_pos3i     *new_pos3i(int x, int y, int z)
{
    t_pos3i *pos;

    if (!(pos = malloc(sizeof(t_pos3i))))
        return (NULL);
    pos->x = x;
    pos->y = y;
    pos->z = z;
    return (pos);
}

/*
** floating positions
*/

t_pos2f     *new_pos2f(float x, float y)
{
    t_pos2f *pos;

    if (!(pos = malloc(sizeof(t_pos2f))))
        return (NULL);
    pos->x = x;
    pos->y = y;
    return (pos);
}

t_pos3f    *new_pos3f(float x, float y, float z)
{
    t_pos3f *pos;

    if (!(pos = malloc(sizeof(t_pos3f))))
        return (NULL);
    pos->x = x;
    pos->y = y;
    pos->z = z;
    return (pos);
}

/*
** double positions
*/

t_pos2d    *new_pos2d(double x, double y)
{
    t_pos2d *pos;

    if (!(pos = malloc(sizeof(t_pos2d))))
        return (NULL);
    pos->x = x;
    pos->y = y;
    return (pos);
}

t_pos3d    *new_pos3d(double x, double y, double z)
{
    t_pos3d *pos;

    if (!(pos = malloc(sizeof(t_pos3d))))
        return (NULL);
    pos->x = x;
    pos->y = y;
    pos->z = z;
    return (pos);
}