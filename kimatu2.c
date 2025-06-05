#include <stdio.h>//ファイル関係とprintfとscanf
#include <stdlib.h>//文字列、NULL、構造体
#include <time.h>//randomなど
#include <string.h>//strcpyなどの文字列関数

/*************定義と使い方*******************************************/
sizeof a//aの大きさを求める

typedef A B;

sizeof(a)/sizeof(a[0])//sizeof(a)は配列aの全体の大きさ/sizeof(a[0])の要素一つの大きさ==要素数を表す(構造体配列には使えない)

sizeof("ABC")==4//なぜならABC\0となっているから\0はナル文字

char str[4]="ABC";//４文字入力することができない最後に\0が存在する。
printf("%s",str);//文字列strを文字として表示、%dなら数となる。一文字なら%c
scanf("%s",str);

char s[個数][文字数];//文字列の配列
scanf("%s",s[個数]);

int str_length(const char p[])//playername[]の文字列を引数とする
{
  int len = 0;//長さは初期で０
  while(p[len])//非０のときにループp[0],p[1],p[2]...５文字ならp[5]は文字がないから0となる。
    len++;
  return len;
}//丸暗記

typedef struct{
  int height;
  double weight;
  char name[256];
}rank_t;

rank_t r[3]={
  {1,3,"ryosuke"},
  {4,5,"taro"},
  {6,4,"hahhah"}
}

int na = aiue(r);

int aiue(rank_t r[]){
  for(int i;i<15;i++){
    r[i].height
    r[i].weight
    printf("%s",r[i].name)
  }
}

srandom(time(NULL));

a=random()%7+1
b=random()%7+1
int atai;
scanf("%d",atai);
char moji[5];
scanf("%s",moji);

int check_moji(const char p[],int nagasa){
  int tmp=0;
  for(int i;i<nagasa;i++){
    if(p[i]>='A'&&p[i]<='Z'){}
      else
  }
//関数内の０か１はtmp返して扱う
//戻したい値が二つ以上のときポインタを使う

int str_length(const char p[])
{
  int len = 0;
  while(p[len] !='\0')
    len++;
  return len;
}

strcpy(r[i].name,r[i-1].name);
#include<string>

#define RANK_FILE "rank.dat"
FILE *fp=fopen("RANK_FILE",r);rとw,rb.wb...

if(fp==NULL){}
else{
  fread(&x,sizeof(int),1,fp);
  fread(a,sizeof(int),n,fp);a[n]
  fread(r,sizeof(rank_t),10,fp);
}
fclose(fp);