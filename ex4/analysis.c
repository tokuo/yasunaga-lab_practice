#include"ex4.h"

void deviation(void* list){
	stock* current = list;
	int num = 0;
	double mean = 0,
			sd = 0;
	while(current->nextValue != NULL){
		mean += current->score;
		num++;
		current = current->nextValue;
	}
	mean += current->score;
	num++;
	mean /= num;
	current = list;
	while(current->nextValue != NULL){
		sd += pow((current->score - mean),2);
		current = current->nextValue;
	}
	sd += pow((current->score - mean),2);
	sd = sqrt(sd/num);
	current = list;
	while(current->nextValue != NULL){
		if(current->score > mean){
			current->score = 50 + (current->score - mean)*10/sd;
		}else{
			current->score = 50 - (mean - current->score)*10/sd;
		}
		current = current->nextValue;
	}
	if(current->score > mean){
		current->score = 50 + (current->score - mean)*10/sd;
	}else{
		current->score = 50 - (mean - current->score)*10/sd;
	}
}

void sumGet(FILE *fpt,void* a){
	stock *current = a;
	if(fscanf(fpt,"%d %d %d %d",&current->num,&current->ana,&current->vec,&current->bio) != EOF){
		current->score = (current->ana + current->vec + current->bio);
		current->nextValue = (stock*)malloc(sizeof(stock));
	}
	while(fscanf(fpt,"%d %d %d %d",&current->nextValue->num,&current->nextValue->ana,&current->nextValue->vec,&current->nextValue->bio) != EOF){
		current->nextValue->score = (current->nextValue->ana + current->nextValue->vec + current->nextValue->bio);
		current = current->nextValue;
		current->nextValue = (stock*)malloc(sizeof(stock));
	}
	current->nextValue = NULL;
	current = a;
	while(current->nextValue != NULL){
		current = current->nextValue;
	}
	fclose(fpt);
}

void sumPut(FILE *fpt,void* list,int flag){
    stock *current = list,*check = list,*swap,*top;
	while(check->nextValue != NULL){
		if(current->score < check->nextValue->score){
			swap = check->nextValue;
			check->nextValue = swap->nextValue;
			swap->nextValue = current;
			current = swap;
		}else{
			check = check->nextValue;
		}
	}
	check = current->nextValue;
	top = current;
	while(current->nextValue->nextValue != NULL){
		if((check->nextValue != NULL)  &&  (current->nextValue->score < check->nextValue->score)){
			swap = check->nextValue;
			current->nextValue = swap;
			check->nextValue = swap->nextValue;
			swap->nextValue = check;
		}else{
			check = check->nextValue;
		}
		while(check->nextValue != NULL){
			if(current->nextValue->score < check->nextValue->score){
				swap = current->nextValue->nextValue;
				current->nextValue->nextValue = check->nextValue->nextValue;
				check->nextValue->nextValue = swap;
				swap = current->nextValue;
				current->nextValue = check->nextValue;
				check->nextValue = swap;
			}
			check = check->nextValue;
		}
		current = current->nextValue;
		check = current->nextValue;
	}
	current=top;
	if(flag == 2){
		deviation(top);
	}
	if(current->nextValue != NULL){
		fprintf(fpt,"%d\t%f\t%d\t%d\t%d\n",current->num,current->score,current->ana,current->vec,current->bio);
	}
	while(current->nextValue != NULL){
		fprintf(fpt,"%d\t%f\t%d\t%d\t%d\n",current->nextValue->num,current->nextValue->score,current->nextValue->ana,current->nextValue->vec,current->nextValue->bio);
		current = current->nextValue;
	}
	fclose(fpt);
}