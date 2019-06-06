#include <stdlib.h>
#include <time.h>

int     random_in_range(int range)
{
  time_t t;

  srand((unsigned) time(&t));
  return (rand() % range);
}