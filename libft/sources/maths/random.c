#include <stdlib.h>
#include <time.h>
#include "../../includes/maths.h"

// usage: set_random = random_in_range(set_random, RAND_MAX);

int     random_in_range(unsigned int set_random, int range)
{
  set_random += (unsigned int)time(NULL);
  srand(set_random);
  return (rand() % range);
}

void    sort_random(t_vec2i *array, int size, int set_random)
{
    int index;
    int random_index;
    t_vec2i tmp;

    index = 0;
    while (index < size)
    {
        set_random = random_in_range(set_random, RAND_MAX);
        random_index = set_random % size;
        tmp = array[index];
        array[index] = array[random_index];
        array[random_index] = tmp;
        index++;
    }
}
