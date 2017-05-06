#include"ex3.h"

int main(int argc,char* argv[]){
	FILE* fpt;
	stock list;
	
	if(NULL==(fpt=fopen(argv[1],"r"))){
		printf("fopen error1!\n");
		return 0;
	}
	yamlGet(fpt,&list);

	if(NULL==(fpt=fopen(argv[2],"r"))){
		fpt = fopen(argv[2],"w");
		yamlPut(fpt,&list);
	}else{
		fpt = fopen(argv[2],"a");
		yamlPut(fpt,&list);
	}

	return 0;
}
