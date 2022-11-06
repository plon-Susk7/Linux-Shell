#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include <stdlib.h>


int main(int argc,char *argv[]){
	int temp;

	if(argc==1){
		printf("mkdir: missing operand\n");
		//return 0;
	}else if(argc==2){
		temp = mkdir(argv[1],0777);
		if(temp==-1){
			printf("Duplicate of the file exits!\n");
			return 0;
		}


	}else if(argc==3){
		if(strcmp(argv[2],"-v")==0){
			temp = mkdir(argv[1],0777);
			if(temp==0){
				printf("mkdir: created directory '%s'\n",argv[1]);
			}else{
				printf("Duplicate of the file exits!\n");
				return 0;
			}
		}else if(strcmp(argv[2],"-i")==0){
			char a;
			printf("Do you want to create directory?(Y/n) ");
			scanf("%c",&a);
			if(a=='Y'){
				int temp = mkdir(argv[1],0777);
				if(temp==-1){
					printf("Duplicate of the file exits!\n");
					return 0;
				}
			}
	
		}
	}

	
}