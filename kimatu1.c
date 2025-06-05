


#include <stdio.h>//ファイル関係とprintfとscanf
#include <stdlib.h>//文字列、NULL、構造体
#include <time.h>//randomなど
#include <string.h>//strcpyなどの文字列関数



#define  RANKING_SIZE 15//ランキング順位のサイズを定義
#define  MAX_NAME_LEN 20//文字列の最大上限を定義
#define  RANKING_FILE “ranking.dat”//保存用のファイルを定義
                                                                                                                                                       


typedef struct {//構造体の定義、typedefはmain関数でstructが必要ないよ
  double ranking_score;//ランキングのスコア(構造体の要素１)
  char ranking_name[MAX_NAME_LEN];//ランキングの名前(構造体の要素２)
}ranking_data_t;//main関数では、ranking_data_tで構造体として認知されることができる。



//①ランキングの表示する関数
int print_ranking(ranking_data_t r[]){//ファイルの読み取りが成功したら新しい構造体配列が引数となる
 printf("\n RANK-----SCORE\n");
 static int number[RANKING_SIZE];//順位のランキング定義;変動しないnumber配列
 for(int i= 0; i < RANKING_SIZE;i++){
  number[i]=i+1;//順位だから配列[0~14]に、値1~15を代入する
  if(r[i-1].ranking_score==r[i].ranking_score){//iのときひとつ上とスコアが等しければ、一つ上の順位と等しくなる。
  	//ex)i=8のときなら  r[7].ranking_score==r[8].ranking_scoreときnumeber[8](7位)にnumber[7](６位)を代入する
    number[i]=number[i-1];//一つ少ないの順位を代入する
    }
  printf("%2d位 -----",number[i]);//ex)i=8ならifの中が成り立てば、６位、成り立ったないなら７位のままである
  printf("%.5f",r[i].ranking_score);//ex)i=8のスコアと名前を表示する
  printf("    %s\n",r[i].ranking_name);
}
}



//②-①ナル文字までの文字列の長さを求めて返す 
int str_length(const char p[])//playername[]の文字列を引数とする
{
  int len = 0;//長さは初期で０
  while(p[len])//非０のときにループp[0],p[1],p[2]...５文字ならp[5]は文字がないから0となる。
    len++;
  return len;
}



//②-②名前の文字の種類を判定する関数（英語の大文字、小文字、数字、ピリオドなら０を返す）
int check_moji(const char p[],int nagasa){//入力した文字列と入力した文字列の長さを引数とする
  int tmp=0;//戻り値の初期化
  for(int i=0;i<nagasa;i++){//p[nagasa]==0だから文字列を一つずつ判定
    if(p[i]>='a'&& p[i]<='z'){}//p[i]の文字のコードの数が'a'aを示す数字と'z'zを示す数字の間の数字かどうか？Abd123..??
      else if(p[i]>='A'&& p[i]<='Z'){}//A123..??
        else if(p[i]>='0'&& p[i]<='9'){}//123..??
          else if(p[i]=='.'){}//..??
            else{//使えない文字なもう一度名前入力させる//??
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
int get_ranking(double score,ranking_data_t r[]){//３ターンのスコア平均とランキング構造体配列を引数
  int tmp;//returnするときの代入する値の宣言
  //ランキングの１位の値からスコアが小さいか比較し、小さいならそのときの順位を表示する
  for(int  i= 0;i < RANKING_SIZE;i++)
    if(r[i].ranking_score>=score){//一位の値から比較する
      printf("%d位です。おめでとう。\n",i+1);//値が小さいことがなったらその時の順位を表示
      while(1){//名前に入力の無条件ループ
        printf("名前を入力してください。");
        scanf("%s",playername);//グローバル関数の中の文字列char playername[文字列の長さ];ここに入力する
          int nagasa = str_length(playername);//②-①入力した文字列の長さを求め、その長さをnagasaに代入して返す
          int nc = check_moji(playername,nagasa);//②-②文字列の種類を判定する
          if(nc==0){//ncには②-②のtmpに値が返る
         break;//名前入力のループを脱出
       }
     }//nc==1ならループ
     tmp = i;//breakしたときの順位の値を記録
     break;
   }//ランキングの最下位の値よりスコアが大きいなら実行
   else if(r[RANKING_SIZE-1].ranking_score <score){//ex)r[14].ranking_score<score
     printf("ランキング外です。\n");
     tmp =  RANKING_SIZE ;//breakしたときにランキングの最下位を記録
     break;
   }
 return tmp;//tmpの値がngに戻る
}



//③ランキングの入れ替え
int update_ranking(double score,int c,ranking_data_t r[]){//自己スコアと自己順位と構造体配列が引数
  for(int i= RANKING_SIZE-1;i>=c;i--){//
    r[i+1].ranking_score = r[i].ranking_score;//一つ下のランキングのスコアにランキングのスコアを代入する
    strcpy(r[i+1].ranking_name,r[i].ranking_name);//一つ下のランキングの名前を置き変える
    //自分の順位が１０位(i=9)ならr[15]←r[14]、r[14]←r[13],r[13]←r[12],r[12]←r[11],r[11]←r[10],
  }
  r[c].ranking_score = score;//スコアを前の順位に代入r[10]←r[9]
  strcpy(r[c].ranking_name,playername);
  //自分の順位tmp→ng→c
}



//④前回のランキングデータを読み込む関数
int load_ranking(ranking_data_t r[]){//引数に構造体配列
   FILE *fp = fopen("RANKING_FILE", "rb");//FILE*fpでFILEのポインタを示す fopen("ファイル名ここでは定義したファイル名","読み込みとバイナリモード")
   if(fp==NULL){//開かないときfpにはNULLが代入される
    printf("\nファイルをオープンできなかった\n");//開かない場合
   }else{//fpがNULLじゃないとき
    printf("\nファイルをオープンできました\n");//開く場合
    //rにポインタfpが示す構造体配列を読み込む sizeは構造体全体、要素は一つの配列で２つだから2*RANKING_SIZE
    fread(r,sizeof(ranking_data_t),RANKING_SIZE*2,fp);
    /*要素が一つのときfread(&a,sizeof(int),1,fp)
    配列の場合r[10]のときfread(r,sizeof(int),10,fp)
    構造体配列のときkouzoutai k[10]={{name,height,weight},...}fread(k,sizeof(kouzoutai),10*3,fp)*/
    fclose(fp);//ファイルを閉じる
   }
}



//⑤新しいデータを保存する関数
int save_ranking(ranking_data_t r[]){//構造体配列の引数
  FILE *fp = fopen("RANKING_FILE", "wb");//書き込みとバイナリモードでRANKING_FILEを開く
  if(fp==NULL){
    printf("ファイルが開きませんでした\n");//開かない場合
   }else{
    fwrite(r,sizeof(ranking_data_t),RANKING_SIZE*2,fp);//構造体配列場合fwrite(配列r,sizeof(構造体ranking_data_t),構造体の要素の合計30,fp)
    fclose(fp);
  }
}



int main(void){
  ranking_data_t r[RANKING_SIZE]={//構造体ranking_data_tの配列r[個数]{{score,name}...}
    {1.00000,"Taro1"},//文字列の場合は"mozi"となる
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
   for(int turn = 1;turn <= 3; turn++;){
     printf("\nターン%dです\n",turn);
     srandom(time(NULL));//答え生成用乱数が同一系列とならないように
     long int r;//乱数rの初期化
     r = random()%100+1;//1~100の乱数生成と初期化
     printf("%ld\n", r);//乱数表示
     /********************************************************************
              予想毎の処理
      *********************************************************************/
     for(int yoso = 0; yoso++;){//条件なし(正解しなければ、予想回数は繰り返し続く)
       printf("第%d回目の予想\n",yoso);
       int atai;//入力aの初期化
       scanf("%d",&atai);//入力
       sum += 1;//全体の予想回数の合計が何回か分かる

       if(r == atai){//入力の値と同じ
         printf("正解！あなたは%d回目の予想で正解しました。\n\n",yoso);
         break;
       }
       else if(r-atai<=3&&r-atai>=-3){//生成した乱数と入力の値との距離が３以内 
       	//以内a<3かつa>-3かつは&&  または||(より大きくより小さいとき)
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
   //ターンの中に何度も予想できる

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

  int nu = update_ranking((double)sum/3,ng,r);//③スコアの入れ替えngは自己順位

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
