#include <stdio.h>

int y = 1000;

int a(int x) 
{
  int i;
  x = x + 10;
  i = x;
  return i;
}

int b(int x)
{
  y = y + x;
  return y; 
}

int main(void) {
  int x;

  x = 100;
  a(x);
  printf("1: %d\n", x); // ■①■
  a(x);
  printf("2: %d\n", x); // ■②■

  x = 200;
  x = a(x);
  printf("3: %d\n", x); // ■③■
  x = a(x);
  printf("4: %d\n", x); // ■④■

  x = 300;
  x = b(x);
  printf("5: %d\n", x); // ■⑤■
  x = b(x);
  printf("6: %d\n", x); // ■⑥■

  return 0;
}