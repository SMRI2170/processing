#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define HAIRETU_SIZE 10


int get_mean(int m[]){
	double tmp=0;
for(int i=0;i<HAIRETU_SIZE;i++){
    tmp +=m[i];
    }
    tmp=tmp/HAIRETU_SIZE;
return tmp;
} 

int get_mean2(int m[]){
	double tmp=0;
for(int i=0;i<HAIRETU_SIZE;i++){
    tmp +=m[i]*m[i];
	}
	tmp=tmp/HAIRETU_SIZE;
return tmp;
}

int main(void){
	int member[HAIRETU_SIZE];
	srandom(time(NULL));
	for(int i=0;i<HAIRETU_SIZE;i++){
		member[i]=random()%10+1;
		printf("%d\n",member[i]);
	}
	double hei =get_mean(member);
	double ni =get_mean2(member);
	printf("\nmean:%f\n",hei);
	printf("mean square:%f\n",ni);

return 0;
}