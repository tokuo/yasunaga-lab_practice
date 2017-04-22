#include<stdio.h>
#include"ex1.h"

int main(int argc,char* argv[]){
	FILE* fpt;
	float a,b;

	if(NULL==(fpt=fopen(argv[1],"r"))){
		printf("fopen error1!\n");
		return 0;
	}
	numberGet(fpt,&a);
	if(NULL==(fpt=fopen(argv[2],"r"))){
		printf("fopen error2!\n");
		return 0;
	}
	numberGet(fpt,&b);
	
	if(average(a,b) >= 0){
		if(NULL==(fpt=fopen(argv[3],"r"))){
			fpt = fopen(argv[3],"w");
			numberPut(fpt,average(a,b));
		}else{
			fpt = fopen(argv[3],"a");
			numberPut(fpt,average(a,b));
		}
	}else{
		printf("not the number of non-negative\n");
	}
	
	return 0;
}
