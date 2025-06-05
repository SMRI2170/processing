#include <stdio.h>
#include <stdlib.h>

int main(void){
char s1[] = "5.3452";
char s2[] = "10.000";
printf("%d %.1f", atoi(s1), atof(s2));
}