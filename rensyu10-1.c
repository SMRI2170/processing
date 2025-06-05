#include <stdio.h>
 
int main()
{
  /* 文字を入力 */
  char moji;
  printf("文字を入力してください = ");
  scanf("%c",&moji);
 
  /* アルファベットか数字かを判定 */
  if( (moji>='a'&& moji<='z') || (moji>='A' && moji<='Z'))
    printf("入力した文字「%c」はアルファベット\n", moji);
  else if(moji>='0'&& moji<='9')
    printf("入力した文字「%c」は数字です。\n", moji);
  else
    printf("「%c」はアルファベットでも数字でもありません。\n", moji);
 
  return 0;
}
