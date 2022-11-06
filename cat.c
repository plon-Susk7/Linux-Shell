#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[]){
	FILE* ptr;
	if(argc==1){
		printf("cat:invalid number of arguments.");
		return 0;
	}

	ptr = fopen(argv[1],"r");
	if(ptr==NULL){
		printf("Error: The file doesn't exist.\n");
		return 0;
	}
	char c;
	if(argc==2){
		while((c=fgetc(ptr))!=EOF){
			printf("%c",c);
		}
		fclose(ptr);
	}else if(argc==3){
		if(strcmp(argv[2],"-E")==0){
			while((c=fgetc(ptr))!=EOF){
				if(c=='\n'){
					printf("$");
				}
				printf("%c",c);
			}
			fclose(ptr);
		}else if(strcmp(argv[2],"-n")==0){
			int j = 1;
			printf("%d ",j);
			int mem=0;
			while((c=fgetc(ptr))!=EOF){
				if(mem==1){
					mem = 0;
					j++;
					printf("%d ",j);
				}

				if(c=='\n'){
					mem = 1;
				}
				printf("%c",c);
			}
			fclose(ptr);

		}
	}
	
	
}