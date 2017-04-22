#include"ex1.h"

void numberGet(FILE *fpt,float* c){
	char readLine[20];
	char check[2] = ".";
	while(fgets(readLine,256,fpt)!=NULL){
		if(strstr(readLine,check)!=NULL){
			*c = atof(readLine);
			break;
		}
	}
}

void numberPut(FILE *fpt,float d){
    fprintf(fpt,"%f\n",d);
	fclose(fpt);
}
