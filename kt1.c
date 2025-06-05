#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define HAIRETU_SIZE 10

int main(void){
	int member[HAIRETU_SIZE];
	srandom(time(NULL));
	for(int i=0;i<HAIRETU_SIZE;i++){
		member[i]=random()%10+1;
		printf("%d\n",member[i]);
	}
	double heikin;
	double nijyoH;
	for(int i=0;i<HAIRETU_SIZE;i++){
    heikin +=member[i];
    nijyou +=member[i]*member[i];
	}
	printf("%d",heikin/HAIRETU_SIZE);
	printf("%d",nijyou/HAIRETU_SIZE);

return 0;
}