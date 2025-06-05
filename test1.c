#include <stdio.h>
#define SIZE 5

int main(void)
{
    int ary[] = {0,4,1,2,3}; // 配列

    for (int i=0; i<SIZE; i++) {
        int tmp; // このブロックの中だけで使える変数tmp
        /* ary[i]とary[ary[i]]を入れ替える */
        tmp = ary[i];
        ary[i] = ary[tmp];
        ary[tmp] = tmp;
    }

    for (int i=0; i<SIZE; i++) {
        printf("ary[%d] = %d\n", i, ary[i]);
    }
}