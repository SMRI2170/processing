#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  srandom(time(NULL));

for(int turn = 1;turn <= 3; turn = turn + 1){

 printf("ターン%dです\n",turn);
 long int r;
 r = random()%100+1;
 printf("%ld\n", r);
 

 for(int yoso = 0; yoso = yoso + 1;){
   
  printf("第%d回目の予想\n",yoso);
  int a;
  scanf("%d",&a);
  
if(r == a){
  printf("正解！あなたは%d回目の予想で正解しました。\n",yoso);

  break;
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

}

}
  return 0;
}
