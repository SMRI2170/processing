#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double ranking[10] ={

  1.00000,
  1.66666,
  2.00000,
  2.33333,
  3.00000,
  4.33333,
  6.66666,
  7.00000,
  7.33333,
  9.00000,
};

int print_ranking(void)
{
  printf("\n RANK-----SCORE\n");
  for(int r= 0; r <= 9; r++){
   printf("%2d位 -----",r+1);printf("%.5f\n",ranking[r]);
  }
}

int t;
int get_ranking(double a){

for(int l = 0;l <= 9;l++){

  if(ranking[l]>=a){
    t = l;
  break;
  }
 }
return t;
}

int update_ranking(int b,double c){
for(int m=8;m>=b;m--){
  ranking[m+1] = ranking[m];
}
  ranking[b] = c ;
}



int main(void){

while(1){

 int nx = print_ranking();

 int sum = 0;

for(int turn = 1;turn <= 3; turn = turn + 1){

 printf("\nターン%dです\n",turn);

 srandom(time(NULL));
 long int r;
 r = random()%100+1;
 printf("%ld\n", r);
 

 for(int yoso = 0; yoso = yoso + 1;){
   
  printf("第%d回目の予想\n",yoso);
  int a;
  scanf("%d",&a);
  sum += 1;
  
  if(r == a){
  printf("正解！あなたは%d回目の予想で正解しました。\n\n",yoso);

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


printf("\n3ターンで%d回の予想をしました。スコア（平均予想回数）は%fです。\n",sum,(double)sum/3);

if(sum==3){
  printf("素晴らしい！！\n");
}
else if(sum<=9){
  printf("すごい！\n");
}
else {
  printf("普通です\n");
}

int ny = get_ranking((double)sum/3);

int nv = update_ranking(t,(double)sum/3);

int nz =  print_ranking();

printf("\nゲームを続けますか(はい:1/いいえ:0)？\n");

int b;
   scanf("%d",&b);
if(b==0){
  exit(0);
}
}
  return 0;

}

  