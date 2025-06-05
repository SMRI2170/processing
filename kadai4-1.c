#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  srandom(time(NULL));

  long int r;
    r = random()%300+1;
   printf("%ld\n", r);

   int a;
  scanf("%d",&a);

  if(r == a){
  printf("正解！\n");
}else{
  printf("不正解！\n");
}
  return 0;
}