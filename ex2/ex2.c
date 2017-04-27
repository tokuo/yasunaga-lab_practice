#include"ex2.h"

int main(int argc,char* argv[]){
	FILE* fpt;
	stock ana;
	
	if(NULL==(fpt=fopen(argv[1],"r"))){
		printf("fopen error1!\n");
		return 0;
	}
	yamlGet(fpt,&ana);

	if(NULL==(fpt=fopen(argv[2],"r"))){
		fpt = fopen(argv[2],"w");
		yamlPut(fpt,0,&ana,0,0);
	}else{
		fpt = fopen(argv[2],"a");
		yamlPut(fpt,0,&ana,0,0);
	}
	
	return 0;
}
