#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  time_t t;
  t = time(0);

  srandom(t);

   int r;
    r = rand();
   printf("%d\n", r);
  

  return 0;
}