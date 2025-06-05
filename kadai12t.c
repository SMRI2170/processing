#include <stdio.h>
#define  RANKING_SIZE 15//ランキングのサイズの定義
#define  MAX_NAME_LEN 20//文字列の最大上限

typedef struct {
  double ranking_score;//スコア
  char name[MAX_NAME_LEN];//名前
}ranking_data_t;

//①ランキングの表示する関数
int print_ranking(void){
  int number[RANKING_SIZE];
 printf("\n RANK-----SCORE\n");
 for(int i= 0; i < RANKING_SIZE;i++){
  number[i]=i+1;//順位だから0~14ではなく、1~15とする
  if(ranking[i-1]==ranking[i]){//iのときひとつ上とスコアが等しければ、一つ上の順位と等しくなる。
    number[i]=number[i-1];//一つ上の順位を代入する
    }
  printf("%2d位 -----",number[i]);
  printf("%.5f",ranking[i]);
  printf("    %s\n",startname[i]);
}
}


int main(void){
  ranking_data_t r[RANKING_SIZE]={
    {1.00000,"Taro1"},
    {1.66666,"Hanak"},
    {2.00000,"Kaoru"},
    {2.33333,"taich"},
    {3.00000,"Ryoma"},
    {3.33333,"12345"},
    {4.33333,"Gaaga"},
    {5.00000,"uio67"},
    {5.33333,"WtoY4"},
    {6.66666,"uuuu9"},
    {7.00000,"mama4"},
    {7.33333,"tani9"},
    {9.00000,"study"},
    {9.33333,"purin"},
    {10.00000,"tata0"}};
//3ターンの回答入力（ゲーム終了の質問で０と回答するとループ終了）
   for(int i=0;i<RANKING_SIZE;i++){
    printf("%2d位 %.5f  %s\n",i+1,r[i].ranking_score,r[i].name);
   }
   return 0;
 }