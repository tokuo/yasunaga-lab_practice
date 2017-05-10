#include"ex6.h"

void check(FILE *fpt,double* ans){
	int num;
    double psh1 = 1,// 1/6
        ps1h0 = 0.5,// 1/2
        psoh0 = 0.1,// 1/10
	swap;
	psh1 /= 6;

	while(fscanf(fpt,"%d",&num) != EOF){
        if(num == 1){
            swap = ps1h0*ans[0]/(ps1h0*ans[0] + psh1*ans[1]);
            ans[1] = psh1*ans[1]/(ps1h0*ans[0] + psh1*ans[1]);
	    ans[0] = swap;
        }else{
            swap = psoh0*ans[0]/(psoh0*ans[0] + psh1*ans[1]);
            ans[1] = psh1*ans[1]/(psoh0*ans[0] + psh1*ans[1]);
	    ans[0] = swap;
        }
	}
	fclose(fpt);
}
