#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  srandom(time(NULL));

  long int r;
    r = random()%100+1;
   //printf("%ld\n", r);

int a;
  scanf("%d",&a);
  /
  if(r == a){
  printf("正解！\n");
}
else if(r-a<=3&&r-a>=-3){
  printf("近い\n");
}
else if(r-a<=15&&r-a>=-15){ 
  printf("まあまあ近い\n");
}
else {
  printf("遠い\n");
}
  return 0;
}