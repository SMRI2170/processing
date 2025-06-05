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
	double hei;
	double ni;
	for(int i=0;i<HAIRETU_SIZE;i++){
    hei +=member[i];
    ni +=member[i]*member[i];
	}
	printf("\nmean:%f\n",hei/HAIRETU_SIZE);
	printf("mean square:%f\n",ni/HAIRETU_SIZE);

return 0;
}