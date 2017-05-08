#include"ex6.h"

void check(FILE *fpt,double* ans){
	int num;
    double psh1 = 1/6,
        ps1h0 = 1/2,
        psoh0 = 1/10;
    
	while(fscanf(fpt,"%d",&num) != EOF){
        if(num == 1){
            ans[0] = ps1h0*ans[0]/(ps1h0*ans[0] + psh1*ans[1]);
            ans[1] = psh1*ans[1]/(ps1h0*ans[0] + psh1*ans[1]);
        }else{
            ans[0] = psoh0*ans[0]/(psoh0*ans[0] + psh1*ans[1]);
            ans[1] = psh1*ans[1]/(psoh0*ans[0] + psh1*ans[1]);
        }
	}
	fclose(fpt);
}