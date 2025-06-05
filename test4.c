
#include <stdio.h>

// 2つの変数の値を交換する関数
void swap2(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return;
}

// 3つの値を小さい値から順に並び替える関数
void sort3(int*n1, int*n2, int*n3)
{
    if (*n1 > *n2) { // n1がn2より大きいときは
        swap2(n1, n2); // n1とn2を入れ替える
    }
    if (*n1 > *n3) { // n1がn3より大きいときは
        swap2(n1, n3); // n1とn3を入れ替える
    }
    if (*n2 > *n3) { // n2がn3より大きいときは
        swap2(n2, n3); // n2とn3を入れ替える
    }
    return;
}

// intの配列を表示する(nは個数)
void print_array(int a[], int n)
{
    for (int i=0; i<n; i++) {
       printf("%d ", a[i]);
    }
    putchar('\n'); // 改行
    return;
}

int main(void)
{
    int ary[3] = {0};
    puts("3つの値を入力します");
    for (int i=0; i<3; i++) {
        printf("%dつ目: ", i+1);
        scanf("%d",ary+i);
    }
    puts("\nソート前");
    print_array(ary, 3);
    sort3(&ary[0], &ary[1], &ary[2]);
    puts("ソート後");
    print_array(ary, 3);
    return 0;
}