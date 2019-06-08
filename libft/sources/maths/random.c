#include <stdlib.h>
#include <time.h>

int     random_in_range(unsigned int set_random, int range)
{
  set_random += (unsigned int)time(NULL);
  srand(set_random);
  return (rand() % range);
}