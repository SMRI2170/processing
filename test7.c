#include<stdio.h>

int main(void){

	FILE *fp;
    double pi = 3.1414251;

    printf("%f\n",pi);

	fp = fopen("abc","r");

	if(fp==NULL){
		printf("not open");
	}else{
	printf("open");
	fclose(fp);
}
return 0;
}