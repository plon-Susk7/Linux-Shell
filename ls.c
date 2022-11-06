#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc,char* argv[]){
	
	DIR *folder= opendir(".");;
	struct dirent *file;
	

	if(argc==1){
		if(folder!= NULL){
			while((file= readdir(folder)) != NULL){
				if(!(strcmp(file->d_name,".")==0 || strcmp(file->d_name,"..")==0))
					printf("%s ",file->d_name );
			}
		}
		printf("\n");
		closedir(folder);
	}else{
		if(strcmp(argv[1],"-1")==0){
			if(folder!= NULL){
			while((file= readdir(folder)) != NULL){
				if(!(strcmp(file->d_name,".")==0 || strcmp(file->d_name,"..")==0))
					printf("%s\n",file->d_name );
			}
		}
		closedir(folder);

		}else if(strcmp(argv[1],"-a")==0){
			if(folder!= NULL){
			while((file= readdir(folder)) != NULL){
				//if(!(strcmp(file->d_name,".")==0 || strcmp(file->d_name,"..")==0))
					printf("%s ",file->d_name );
			}
			}
			closedir(folder);
		}

	}

}

