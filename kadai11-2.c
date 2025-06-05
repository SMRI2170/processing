#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define  RANKING_SIZE 15//ランキングのサイズの定義
#define  MAX_NAME_LEN 20//文字列の最大上限

//ランキングの配列の初期化
double ranking[RANKING_SIZE] ={
  1.00000,
  1.66666,
  2.00000,
  2.33333,
  3.00000,

  3.33333,
  4.33333,
  5.00000,
  5.33333,
  6.66666,

  7.00000,
  7.33333,
  9.00000,
  9.33333,
  10.00000,
};

char startname[RANKING_SIZE][MAX_NAME_LEN]= 
{"Taro","Hanako","Kaoru12","Taichi..","RyoMa",
"12345","AIUEO","IMO","uuuu","WtoY",
"tata","purin","study","tani19","mama"};//名前の初期化

char playername[MAX_NAME_LEN]={0};//入力する名前

int number[RANKING_SIZE];//順位のランキング定義


//①ランキングの表示する関数
int print_ranking(void){
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


//④ナル文字までの文字列の長さを求めて返す 
int str_length(const char p[])
{
  int len = 0;
  while(p[len])
    len++;
  return len;
}




//⑤名前の文字の種類を判定する関数（英語の大文字、小文字、数字、ピリオドなら０を返す）
int check_moji(const char p[],int nagasa){
  int tmp=0;
  for(int i=0;i<nagasa;i++){
    if(p[i]>='a'&& p[i]<='z'){}
      else if(p[i]>='A'&& p[i]<='Z'){}
        else if(p[i]>='0'&& p[i]<='9'){}
          else if(p[i]=='.'){}
            else{//使えない文字なもう一度名前入力させる
              tmp =1;
              break;
            }
          }
          if(nagasa>20){//文字列が２０以上ならもう一度名前入力させる
            tmp =1;
          }
          return tmp;
        }



//②予想に伴う順位報告する関数
        int t;
        int get_ranking(double a){
  //ランキングの１位の値からスコアが小さいか比較し、小さいならそのときの順位を表示する
         for(int  i= 0;i < RANKING_SIZE;i++)
          if(ranking[i]>=a){
            printf("%d位です。おめでとう。\n",i+1);
            while(1){
              printf("名前を入力してください。");
              scanf("%s",playername);
          int nagasa = str_length(playername);//文字列の長さを求める
          int nc = check_moji(playername,nagasa);//文字列の種類を判定する
          if(nc==0){
         break;//名前入力のループを脱出
       }
     }
     t = i;//breakしたときの順位の値を記録
     break;
   }//ランキングの最下位の値よりスコアが大きいなら実行
   else if(ranking[RANKING_SIZE-1] <a){
     printf("ランキング外です。\n");
     t =  RANKING_SIZE ;//breakしたときにランキングの最下位を記録
     break;
   }
 return t;//tの値がnyに戻る
}




//③ランキングの入れ替え
int update_ranking(double b,int c){
  for(int i= RANKING_SIZE-1;i>=c;i--){
    ranking[i+1] = ranking[i];//ランキングの最下位に一つ上のランキングのスコアを代入する
    strcpy(startname[i+1],startname[i]);
  }
  ranking[c] = b;//スコアを前の順位に代入
  strcpy(startname[c],playername);//自分の順位t→ny→c
}



int main(void){
//3ターンの回答入力（ゲーム終了の質問で０と回答するとループ終了）
  while(1){
   int nx = print_ranking();//ランキング表示
   int sum = 0;//予想回数の合計の初期化
   /***************************************************************
              ターン毎の処理
   *****************************************************************/
   for(int turn = 1;turn <= 3; turn = turn + 1){
     printf("\nターン%dです\n",turn);
     srandom(time(NULL));//答え生成用乱数が同一系列とならないように
     long int r;//乱数rの初期化
     r = random()%100+1;//1~100の乱数生成と初期化
     printf("%ld\n", r);//乱数表示
     /********************************************************************
              予想毎の処理
      *********************************************************************/
     for(int yoso = 0; yoso = yoso + 1;){//条件なし(正解しなければ、予想回数は続く)
       printf("第%d回目の予想\n",yoso);
       int a;//入力aの初期化
       scanf("%d",&a);//入力
       sum += 1;//全体の予想回数の合計が何回か分かる

       if(r == a){//入力値と同じ
         printf("正解！あなたは%d回目の予想で正解しました。\n\n",yoso);
         break;
       }
       else if(r-a<=3&&r-a>=-3){//生成した乱数と入力値との距離が３以内
         printf("近い\n");
       }
       else if(r-a<=15&&r-a>=-15){ //生成した乱数と入力値との距離が１５以内
         printf("まあまあ近い\n");
       }
       else {
         printf("遠い\n");
       }
     }//予想ループの終了
   }//ターンループの終了

   printf("\n3ターンで%d回の予想をしました。スコア（平均予想回数）は%fです。\n",sum,(double)sum/3);//３ターンの予想平均

   if(sum==3){
    printf("素晴らしい！！\n");
  }
  else if(sum<=9){
    printf("すごい！\n");
  }
  else {
    printf("普通です\n");
  }

  int ny = get_ranking((double)sum/3);//スコアの順位報告

  int nz = update_ranking((double)sum/3,ny);//スコアの入れ替え

  int nw =  print_ranking();//ランキングの表示

  printf("\nゲームを続けますか(はい:1/いいえ:0)？\n");

  int b;
  scanf("%d",&b);
  if(b==0){//入力値が0のとき正常終了を行う
    exit(0);
  }
}//無限ループ
return 0;
}

