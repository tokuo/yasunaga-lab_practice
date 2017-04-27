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
}

void yamlPut(FILE *fpt, char* term, void* value, int type, int mode){
    stock* current = value;
	int num = 0;
	double mean = 0,
			dispersion,
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
	//sd,skewness,kurtosis
	current = value;
	while(current->nextValue != NULL){
		sd += pow((current->value - mean),2);
		skewness += pow((current->value),3);
		kurtosis += pow((current->value),4);
	}
	dispersion = sd/num;
	sd = pow(dispersion,(1/2));
	skewness = skewness/(num*pow(dispersion,(3/2)));
	kurtosis = kurtosis/(num*pow(dispersion,2));
	//se
	se = sd/pow(num,(1/2));

	fprintf(fpt," mean: %f\n sd: %f¥n se: %f¥n skewness: %f¥n kurtosis: %f",mean,sd,se,skewness,kurtosis);

	fclose(fpt);
}
