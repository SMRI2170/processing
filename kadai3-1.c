#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  long int t;
  t = time(0);

  srandom(t);

   int r;
    r = random();
   printf("%d\n", r);
  

  return 0;
}