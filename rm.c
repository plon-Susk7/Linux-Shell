#include<stdio.h>
#include<string.h>


int main(int argc,char* argv[]){
	if(argc==1){
		printf("rm:invalid operand at the end!\n");
		return 0;
	}

	if(argc==2){
		if(remove(argv[1])!=0){
			printf("Unable to delete the file!\n");
		}
	}else if(argc==3){
		char temp;
		if(strcmp(argv[2],"-i")==0){
			printf("Do you want to delete the file?(Y/n)\n ");
			scanf("%c",&temp);
			if(temp=='Y'){
				remove(argv[1]);
			}
		}else if(strcmp(argv[2],"-v")==0){
			if(remove(argv[1])==0){
				printf("removed '%s'\n",argv[1]);
			}else{
				printf("Unable to remove the file!\n");
			}
		}
		
	}
}