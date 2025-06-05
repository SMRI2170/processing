#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define HAIRETU_SIZE 3
#define MOJI_SIZE 11

typedef struct
{   int member;
    char name[HAIRETU_SIZE];
}ran_t;




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
   ran_t r[];

	int member[HAIRETU_SIZE];
	char name[HAIRETU_SIZE][MOJI_SIZE];
    srandom(time(NULL));

for(int i=0;i<HAIRETU_SIZE;i++){
	printf("%dの名前：\n",i+1);
	
	while(1){scanf("%s",name[i]);
	int len=0;
	while(name[i][len]){
		len++;
	}
	if(len>10){
	}else{
		break;}
	}

}

for(int i=0;i<HAIRETU_SIZE;i++){
		member[i]=random()%10+1;
		printf("%s %d\n",name[i],member[i]);
	}

	double hei =get_mean(member);
	double ni =get_mean2(member);
	printf("\nmean:%f\n",hei);
	printf("mean square:%f\n",ni);


return 0;
}