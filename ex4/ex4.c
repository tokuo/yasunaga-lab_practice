#include"ex4.h"

int main(int argc,char* argv[]){
	FILE* fpt;
	stock list;
	
	if(NULL==(fpt=fopen(argv[1],"r"))){
		printf("fopen error1!\n");
		return 0;
	}
	sumGet(fpt,&list);

	if(NULL==(fpt=fopen(argv[2],"r"))){
		fpt = fopen(argv[2],"w");
		sumPut(fpt,&list,atoi(argv[3]));
	}else{
		fpt = fopen(argv[2],"a");
		sumPut(fpt,&list,atoi(argv[3]));
	}
	return 0;
}
