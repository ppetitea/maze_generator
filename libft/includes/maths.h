#ifndef MATHS_H
# define MATHS_H

/*
** sizes
*/

typedef struct   s_size
{
    int     x;
    int     y;
}               t_size;

/*
** range
*/

typedef struct   s_range
{
    int     min;
    int     max;
}               t_range;

t_size  size(int x, int y);

/*
** integer positions
*/

typedef struct   s_pos2i
{
    int     x;
    int     y;
}               t_pos2i;

t_pos2i     *new_pos2i(int x, int y);
t_pos2i     pos2i(int x, int y);
void        *pos2i_add(t_pos2i *pos1, t_pos2i *pos2);

typedef struct   s_pos3i
{
    int     x;
    int     y;
    int     z;
}               t_pos3i;

t_pos3i     *new_pos3i(int x, int y, int z);

/*
** floating positions
*/

typedef struct   s_pos2f
{
    float     x;
    float     y;
}               t_pos2f;

t_pos2f     *new_pos2f(float x, float y);

typedef struct   s_pos3f
{
    float     x;
    float     y;
    float     z;
}               t_pos3f;

t_pos3f    *new_pos3f(float x, float y, float z);

/*
** double positions
*/

typedef struct   s_pos2d
{
    double     x;
    double     y;
}               t_pos2d;

t_pos2d    *new_pos2d(double x, double y);

typedef struct   s_pos3d
{
    double     x;
    double     y;
    double     z;
}               t_pos3d;

t_pos3d    *new_pos3d(double x, double y, double z);

/*
** integer movements
*/

typedef struct   s_vec2i
{
    int     x;
    int     y;
}               t_vec2i;

t_vec2i     vec2i(int x, int y);

/*
** Random section
*/

int     random_in_range(unsigned int set_random, int range);
void    sort_random(t_vec2i *array, int size, int set_random);

#endif