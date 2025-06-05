#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  srandom(time(NULL));

  long int r;
    r = random();
   printf("%ld\n", r);

  return 0;
}