#include"ex2.h"

void yamlGet(FILE *fpt,void* a){
	char readLine[20];
	stock* current = a;
	if(fgets(readLine,256,fpt)!=NULL){
		current->value = atof(readLine);
	}
	while(fgets(readLine,256,fpt)!=NULL){
		current->nextValue = (stock*)malloc(sizeof(stock));
		current = current->nextValue;
		current->value = atof(readLine);
	}
	current->nextValue = NULL;
	fclose(fpt);
}

void yamlPut(FILE *fpt,void* value){
    stock* current = value;
	int num = 0;
	double mean = 0,
			sd = 0,
			se,
			skewness = 0,
			kurtosis = 0;
	//mean
	while(current->nextValue != NULL){
		mean += current->value;
		num++;
		current = current->nextValue;
	}
	mean /= num;
	//sd,skewness,kurtosis　　ここちょっとおかしい
	current = value;
	while(current->nextValue != NULL){
		sd += pow((current->value - mean),2);
		skewness += pow((current->value),3);
		kurtosis += pow((current->value),4);
		current = current->nextValue;
	}
	sd = pow((sd/num),(1/2));
	skewness = skewness/(num * pow(sd,3));
	kurtosis = kurtosis/(num * pow(sd,4));
	//se
	se = sd/pow(num,(1/2));

	fprintf(fpt,"mean: %f \nsd: %f \nse: %f \nskewness: %f \nkurtosis: %f",mean,sd,se,skewness,kurtosis);
	fclose(fpt);
}
