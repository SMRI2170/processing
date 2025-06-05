#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	
    printf("trial1:");

    int ar;
    srandom(time(NULL));
    ar = random()%7+1;
    printf("a=%d ",ar );
	int br;
	
	br = random()%7+1;
    printf("b=%d ",br );
    int cr;
    
    cr = random()%7+1;
    printf("c=%d\n",cr );

    printf("trial2:");
    int arr;
    
    arr = random()%7+1;
    printf("a=%d ",arr );
    int brr;
    
    brr = random()%7+1;
    printf("b=%d ",brr );
    int crr;
    
    crr = random()%7+1;
    printf("c=%d\n ",crr );
    
    printf("trial3:");
    int arrr;
    
    arrr = random()%7+1;
    printf("a=%d ",arrr );
    int brrr;
    
    brrr = random()%7+1;
    printf("b=%d ",brrr );
    int crrr;
    
    crrr = random()%7+1;
    printf("c=%d ",crrr );
    
	return 0;
}