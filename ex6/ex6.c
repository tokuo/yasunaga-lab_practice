#include"ex6.h"

int main(int argc,char* argv[]){
    FILE* fpt;
    double ans[] = {0.5,0.5};//偽、真の順
    
	if(NULL==(fpt=fopen(argv[1],"r"))){
		printf("fopen error1!\n");
		return 0;
	}
    check(fpt,ans);
    
    printf("真:%f\t偽:%f\n",ans[1],ans[0]);
    return 0;
}
