#include"ex5.h"

void maingre(void* list,void* avelists){
	stock* current = list;
	AVE* avelist = avelists;
	double mat[3][3],q[3][3],r[3][3],swap=0,a[3][3];
	int i,j,k;
	while(current->nextValue != NULL){
		mat[0][0] += pow((current->ana - avelist->ana),2);
		mat[0][1] += (current->ana - avelist->ana)*(current->ana - avelist->vec);
		mat[0][2] += (current->ana - avelist->ana)*(current->ana - avelist->bio);
		mat[1][1] += pow((current->vec - avelist->vec),2);
		mat[1][2] += (current->vec - avelist->vec)*(current->vec - avelist->bio);
		mat[2][2] += pow((current->bio - avelist->bio),2);
		current = current ->nextValue;
	}
	mat[0][0] += pow((current->ana - avelist->ana),2);
	mat[0][1] += (current->ana - avelist->ana)*(current->ana - avelist->vec);
	mat[0][2] += (current->ana - avelist->ana)*(current->ana - avelist->bio);
	mat[1][1] += pow((current->vec - avelist->vec),2);
	mat[1][2] += (current->vec - avelist->vec)*(current->vec - avelist->bio);
	mat[2][2] += pow((current->bio - avelist->bio),2);
	//mat complete
	mat[0][0] /= avelist->numP;
	mat[0][1] /= avelist->numP;
	mat[0][2] /= avelist->numP;
	mat[1][0] = mat[0][1];
	mat[1][1] /= avelist->numP;
	mat[1][2] /= avelist->numP;
	mat[2][0] = mat[0][2];
	mat[2][1] = mat[1][2];
	mat[2][2] /= avelist->numP;
	//以下、固有値固有ベクトルの算�
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			swap += pow(mat[j][i],2);
		}
		swap = sqrt(swap);
		for(j=0;j<3;j++){
			q[j][i] = mat[j][i]/swap;
		}
		swap = 0;
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			r[i][j] = 0;
			for(k=0;k<3;k++){
				r[i][j] += q[k][i]*mat[k][j];
			}
		}
	}
	//QR algorithm http://marupeke296.com/oxmath_no3_eigenvalues.html
}

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

void sumGet(FILE *fpt,void* a,void* avelists){
	stock *current = a;
	AVE* avelist = avelists;
	int numP = 0;
	avelist->ana = 0;
	avelist->vec = 0;
	avelist->bio = 0;
	if(fscanf(fpt,"%d %d %d %d",&current->num,&current->ana,&current->vec,&current->bio) != EOF){
		current->score = (current->ana + current->vec + current->bio);
		avelist->ana += current->ana;
		avelist->vec += current->vec;
		avelist->bio += current->bio;
		current->nextValue = (stock*)malloc(sizeof(stock));
		numP++;
	}
	while(fscanf(fpt,"%d %d %d %d",&current->nextValue->num,&current->nextValue->ana,&current->nextValue->vec,&current->nextValue->bio) != EOF){
		current->nextValue->score = (current->nextValue->ana + current->nextValue->vec + current->nextValue->bio);
		avelist->ana += current->ana;
		avelist->vec += current->vec;
		avelist->bio += current->bio;
		current = current->nextValue;
		current->nextValue = (stock*)malloc(sizeof(stock));
		numP++;
	}
	current->nextValue = NULL;
	avelist->numP = numP;
	avelist->ana /= numP;
	avelist->vec /= numP;
	avelist->bio /= numP;
	current = a;
	while(current->nextValue != NULL){
		current = current->nextValue;
	}
	fclose(fpt);
}

void sumPut(FILE *fpt,void* list,int flag,void* avelist){
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
	if(flag == 1 || flag == 2){
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
	}
	if(flag == 2){
		deviation(top);
	}else if(flag == 3){
		maingre(top,avelist);
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
