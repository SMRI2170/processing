#include<stdio.h>//printf 宣言
#include<stdlib.h>//random宣言とNULLとexit()
#include<time.h>//time宣言
#define SIZE 10//SIZEと書いているところを変数として考えることができるプログラムすべて変える必要がない

double//８桁くらい表示できる
int   //基本整数
double ranking[10]={０
};//１０個の配列と初期値これは全部０となる。{1,2,3,}で囲むと初期値を設定できる[0]~[9]までで[10]はない あくまで数を表す

int aiueo(void){};
int kaiueo(int c){};//関数定義()は引数（int a,int b,double c)のように設定できるreturnで返す
int na = aiueo();//呼び出し
int nk = kaiueo(32);//引数代入して実行できる

int main(void){//これの中にないものをグローバル関数という
	return 0;//終わらせる
}
printf("%dです。\n",kansu);//(%dに関数の値が代入されて表示される) kansuがdoubleなら%fにする long intなら%ldにする
scanf("%d",&a);//aは宣言しておく 入力関数 doubleなら%lf long int なら%ld
//%3d なら上三桁まで%.5dなら下五桁まで

while(1){}//無限ループ
exit(0);//正常終了

do{  }while();//while()が成り立つとき、doの中身が繰り返される
for(int i=0;i<=10;i++){}//;いらない １基本宣言と初期値 ２ループ条件 ３加算や引算
for(int i=9;i>=1;i--){}
break;//囲んでいる一つ目のループから出る

if(a==o){原点}//こんな感じ 等しいときは＝＝ イコールひとつでは代入となる
else if(a>0){正}//()が成り立つなら実行
	else{負}//同様

&&//はかつ－3以上３以下のとき
(a<=3&&a>=-3)
||//はまたは
(a>=3||a<-3)
srandom(time(NULL));//答え生成用乱数が同一系列とならないように
     long int r;
     r = random()%100+1;//下二桁




#include <string.h>//文字列の置き換え関数使用

typedef struct {
  double ranking_score;
  char ranking_name[MAX_NAME_LEN];//charは文字列宣言に利用、[]は文字列も字数制限
}ranking_data_t;//構造体宣言グローバル関数

//→main関数に
ranking_data_t r[RANKING_SIZE]={//ranking_data_tは構造体名、r[RANKING_SIZE]は配列の個数
    {1.00000,"Taro1"},
    {1.66666,"Hanak"},
    {2.00000,"Kaoru"},
  };//のように宣言することができる。

//データの読み込み
FILE *fp;//fpがFILE型のポインタ
fp=fopen("RANKING_FILE","r");//"ファイル名"、"モード名"
//