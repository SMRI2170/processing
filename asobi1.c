#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

	while(1){
int r;
srandom(time(NULL));
r=random()%10+1;
 printf("%d", r);


	}


	return 0;
}