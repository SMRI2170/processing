

/*
#include <stdio.h>

void print_surf(int a[][3][2], int z)
{
    for(int y=0; y<3; y++) {
        for(int x=0; x<2; x++) {
            printf("%2d ", a[z][y][x]);
        }
        putchar('\n');
    }
}

int main(void)
{
    int ary[4][3][2] = {{{ 1, 2},{ 3, 4},{ 5, 6}}, 
                        {{ 7, 8},{ 9,10},{11,12}},
                        {{13,14},{15,16},{17,18}},
                        {{19,20},{21,22},{23,24}}};
    int s;
    scanf("%d",&s);
    print_surf(ary,s);
}
*/


#include <stdio.h>

int y = 10;

int a(int x)
{
    int y = 20;
    y = x + y;
    return y;
}

int b(int x)
{
    static int y = 30;
    y = x + y;
    return y;
}

int c(int x)
{
    y = x + y;
    return y;
}

int main(void)
{
    for (int i=0; i<5; i++) {
        a(1);
        b(1);
        c(1);
    }
    printf("a(0)=%d b(0)=%d c(0)=%d\n", a(0), b(0), c(0));

    return 0;
}

