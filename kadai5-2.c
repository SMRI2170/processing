#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  srandom(time(NULL));
 int sum = 0;
for(int turn = 1;turn <= 3; turn = turn + 1){

 printf("ターン%dです\n",turn);
 long int r;
 r = random()%100+1;
 printf("%ld\n", r);
 

 for(int yoso = 0; yoso = yoso + 1;){
   
  printf("第%d回目の予想\n",yoso);
  int a;
  scanf("%d",&a);
  sum += 1;
  
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


printf("3ターンで%d回の予想をしました。スコア（平均予想回数）は%fです。\n",sum,(double)sum/3);

if(sum==3){
  printf("素晴らしい\n");
}
else if(sum<=9){
  printf("すごい\n");
}
else {
  printf("普通\n");
}
  return 0;
}
