#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define  RANKING_SIZE 15//ランキングのサイズの定義
#define  MAX_NAME_LEN 20//文字列の最大上限
#define  RANKING_FILE “ranking.dat”//保存用のファイル

typedef struct {
  double ranking_score;//ランキングのスコア
  char ranking_name[MAX_NAME_LEN];//ランキングの名前
}ranking_data_t;


//①ランキングの表示する関数
int print_ranking(ranking_data_t r[]){
 printf("\n RANK-----SCORE\n");
 static int number[RANKING_SIZE];//順位のランキング定義
 for(int i= 0; i < RANKING_SIZE;i++){
  number[i]=i+1;//順位だから0~14ではなく、1~15とする
  if(r[i-1].ranking_score==r[i].ranking_score){//iのときひとつ上とスコアが等しければ、一つ上の順位と等しくなる。
    number[i]=number[i-1];//一つ上の順位を代入する
    }
  printf("%2d位 -----",number[i]);
  printf("%.5f",r[i].ranking_score);
  printf("    %s\n",r[i].ranking_name);
}
}


//②-①ナル文字までの文字列の長さを求めて返す 
int str_length(const char p[])
{
  int len = 0;
  while(p[len])
    len++;
  return len;
}


//②-②名前の文字の種類を判定する関数（英語の大文字、小文字、数字、ピリオドなら０を返す）
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
char playername[MAX_NAME_LEN];//入力する名前       


//②予想に伴う順位報告する関数
int get_ranking(double score,ranking_data_t r[]){
  int t;
  //ランキングの１位の値からスコアが小さいか比較し、小さいならそのときの順位を表示する
  for(int  i= 0;i < RANKING_SIZE;i++)
    if(r[i].ranking_score>=score){
      printf("%d位です。おめでとう。\n",i+1);
      while(1){
        printf("名前を入力してください。");
        scanf("%s",playername);
          int nagasa = str_length(playername);//②-①文字列の長さを求める
          int nc = check_moji(playername,nagasa);//②-②文字列の種類を判定する
          if(nc==0){
         break;//名前入力のループを脱出
       }
     }
     t = i;//breakしたときの順位の値を記録
     break;
   }//ランキングの最下位の値よりスコアが大きいなら実行
   else if(r[RANKING_SIZE-1].ranking_score <score){
     printf("ランキング外です。\n");
     t =  RANKING_SIZE ;//breakしたときにランキングの最下位を記録
     break;
   }
 return t;//tの値がnyに戻る
}


//③ランキングの入れ替え
int update_ranking(double score,int c,ranking_data_t r[]){
  for(int i= RANKING_SIZE-1;i>=c;i--){
    r[i+1].ranking_score = r[i].ranking_score;//一つ下のランキングのスコアにランキングのスコアを代入する
    strcpy(r[i+1].ranking_name,r[i].ranking_name);//一つ下のランキングの名前を置き変える
  }
  r[c].ranking_score = score;//スコアを前の順位に代入
  strcpy(r[c].ranking_name,playername);//自分の順位t→ny→c
}


//④前回のランキングデータを読み込む関数
int load_ranking(ranking_data_t r[]){
   FILE *fp = fopen("RANKING_FILE", "rb");//読み込みとバイナリモード
   if(fp==NULL){
    printf("\nファイルをオープンできなかった\n");//開かない場合
   }else{
    printf("\nファイルをオープンできました\n");//開く場合
    //rにポインタfpが示す構造体配列を読み込む sizeは構造体全体、要素は一つの配列で２つだから2*RANKING_SIZE
    fread(r,sizeof(ranking_data_t),RANKING_SIZE*2,fp);
    fclose(fp);
   }
}


//⑤新しいデータを保存する関数
int save_ranking(ranking_data_t r[]){
  FILE *fp = fopen("RANKING_FILE", "wb");//書き込みとバイナリモード
  if(fp==NULL){
    printf("ファイルが開きませんでした\n");//開かない場合
   }else{
    printf("ファイルが開きました\n");
    fwrite(r,sizeof(ranking_data_t),RANKING_SIZE*2,fp);
    fclose(fp);
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
    {9.66666,"tata0"}
  };
//3ターンの回答入力（ゲーム終了の質問で０と回答するとループ終了）
  while(1){
   
   int nl = load_ranking(r);//④前回のランキングのデータを読み込む関数

   int np1 = print_ranking(r);//①ランキングを表示する関数
   
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
       int atai;//入力aの初期化
       scanf("%d",&atai);//入力
       sum += 1;//全体の予想回数の合計が何回か分かる

       if(r == atai){//入力の値と同じ
         printf("正解！あなたは%d回目の予想で正解しました。\n\n",yoso);
         break;
       }
       else if(r-atai<=3&&r-atai>=-3){//生成した乱数と入力の値との距離が３以内
         printf("近い\n");
       }
       else if(r-atai<=15&&r-atai>=-15){ //生成した乱数と入力の値との距離が１５以内
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
  }else{
    printf("普通です\n");
  }

  int ng = get_ranking((double)sum/3,r);//②スコアの順位報告

  int nu = update_ranking((double)sum/3,ng,r);//③スコアの入れ替え

  int np2 =  print_ranking(r);//①ランキングを表示する関数

  int ns = save_ranking(r);//⑤の新しいランキングのデータを保存する関数

   printf("\nゲームを続けますか(はい:1/いいえ:0)？\n");

  int b;
  scanf("%d",&b);
  if(b==0){//入力値が0のとき正常終了を行う
    exit(0);
  }
}//無限ループ
return 0;
}
