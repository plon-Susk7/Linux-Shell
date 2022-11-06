#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h>  
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <pthread.h>


struct custom_ds{
	char *temp[100];
};


void *thread_func(void* argv){
	struct custom_ds *temp1 = (struct custom_ds*)argv;
	char *exc[100];
	int z=0;
	while(temp1->temp[z]!=NULL){
		exc[z] = temp1->temp[z];
		//printf("%s\n",temp1->temp[i]);
		z++;
	}
	exc[z] = NULL;
	char root_folder[100];
   	getcwd(root_folder,sizeof(root_folder));
	int j = 0;
		while(exc[j]!=NULL){
			j++;
		}

	if(j==2){
				char a[100];
				if(strcmp(exc[0],"ls")==0){
					strcat(root_folder,"/ls");
					
					sprintf(a,"%s",root_folder);

					system(a);
				}else if(strcmp(exc[0],"date")==0){
					strcat(root_folder,"/date");
					sprintf(a,"%s",root_folder);
					system(a);
				}else if(strcmp(exc[0],"mkdir")==0){
					strcat(root_folder,"/mkdir");

					sprintf(a,"%s",root_folder);
					system(a);
				}else if(strcmp(exc[0],"cat")==0){
					strcat(root_folder,"/cat");

					sprintf(a,"%s",root_folder);
					system(a);
				}else if(strcmp(exc[0],"rm")==0){
					strcat(root_folder,"/rm");

					sprintf(a,"%s",root_folder);
					system(a);
				}
			}else{
				char a[1000];
				if(strcmp(exc[0],"ls")==0){
					exc[2][strlen(exc[2]) - 1] = '\0';
					strcat(root_folder,"/ls");
					sprintf(a,"%s %s",root_folder,exc[1]);
					system(a);
					//execv(root_folder,exc);
				}else if(strcmp(exc[0],"date")==0){
						exc[2][strlen(exc[2]) - 1] = '\0';
						strcat(root_folder,"/date");
						sprintf(a,"%s %s",root_folder,exc[1]);
						system(a);
						//execv(root_folder,exc);
				}else if(strcmp(exc[0],"mkdir")==0){
					if(j==3){
						//exc[2][strlen(exc[2]) - 1] = '\0';
						strcat(root_folder,"/mkdir");
						sprintf(a,"%s %s",root_folder,exc[1]);
						system(a);
					}else if(j==4){
						//exc[3][strlen(exc[3]) - 1] = '\0';
						strcat(root_folder,"/mkdir");
						sprintf(a,"%s %s %s",root_folder,exc[1],exc[2]);
						system(a);
						//execv(root_folder,exc);
					}
				}else if(strcmp(exc[0],"cat")==0){
					if(j==3){
						//exc[2][strlen(exc[2]) - 1] = '\0';
						strcat(root_folder,"/cat");
						sprintf(a,"%s %s",root_folder,exc[1]);
						system(a);
						//execv(root_folder,exc);
					}else if(j==4){
						//exc[3][strlen(exc[3]) - 1] = '\0';
						strcat(root_folder,"/cat");
						sprintf(a,"%s %s %s",root_folder,exc[1],exc[2]);
						system(a);
						//execv(root_folder,exc);
					}
				}else if(strcmp(exc[0],"rm")==0){
					if(j==3){
						//exc[2][strlen(exc[2]) - 1] = '\0';
						strcat(root_folder,"/rm");
						sprintf(a,"%s %s",root_folder,exc[1]);
						system(a);
						//execv(root_folder,exc);
					}else if(j==4){
						//exc[3][strlen(exc[3]) - 1] = '\0';
						strcat(root_folder,"/rm");
						sprintf(a,"%s %s %s",root_folder,exc[1],exc[2]);
						system(a);
						//execv(root_folder,exc);
					}
				}
		}
}

int main(){

	char root_folder[100];
   	getcwd(root_folder,sizeof(root_folder));

	while(1){
		char wd[100];

	    printf("$shell/");
		printf("%s>",getcwd(wd,sizeof(wd)));
		char cmd[100];
		fgets(cmd,100,stdin);
		char *inCmd[3];
		
		char *exc[100];
		char* token = NULL;

	    token = strtok(cmd, " ");
	    int i = 0;
	    while (token != NULL) {
	        exc[i] = token;
	        token = strtok(NULL, " ");
	        i++;
	    }

	    
	    exc[i] = NULL;

		//Internal Commands
		inCmd[0] = "pwd\n";
		inCmd[1] = "exit\n";
		inCmd[2] = "echo";
		inCmd[3] = "cd";
		
		//This array is defined for getcwd command
		


		//main command
		if(strcmp(exc[0],inCmd[0])==0){
			printf("%s",getcwd(wd,sizeof(wd)));
			printf("\n");
		}else if(strcmp(exc[0],inCmd[1])==0){
			break;
		}else if(strcmp(exc[0],inCmd[2])==0){
				i=1;
				while(exc[i]!= NULL){
					printf("%s ",exc[i] );
					i++;
				}
			printf("\n");			
		}else if(strcmp(exc[0],inCmd[3])==0){
			exc[1][strlen(exc[1]) - 1] = '\0';
			chdir(exc[1]);
		}

		int j = 0;
		while(exc[j]!=NULL){
			j++;
		}

		struct custom_ds *temp1 = (struct custom_ds*)malloc(sizeof(struct custom_ds));
		
		for(int i=0;i<j;i++){
			temp1->temp[i] = exc[i];
		}

		if(strcmp(exc[j-1],"&t\n")==0){
			//printf("Hello World!");

			pthread_t thread_id;
		    pthread_create(&thread_id, NULL, thread_func, (void *)temp1);
		    pthread_join(thread_id, NULL);
		    // printf("After Thread\n");
		   // pthread_exit(NULL);
		}else{
			if(fork()==0){
			if(j==1){
				if(strcmp(exc[0],"ls\n")==0){
					strcat(root_folder,"/ls");
					execv(root_folder,exc);
				}else if(strcmp(exc[0],"date\n")==0){
					strcat(root_folder,"/date");
					execv(root_folder,exc);
				}else if(strcmp(exc[0],"mkdir\n")==0){
					strcat(root_folder,"/mkdir");
					execv(root_folder,exc);
				}else if(strcmp(exc[0],"cat\n")==0){
					strcat(root_folder,"/cat");
					execv(root_folder,exc);
				}else if(strcmp(exc[0],"rm\n")==0){
					strcat(root_folder,"/rm");
					execv(root_folder,exc);
				}
			}else{
				
				if(strcmp(exc[0],"ls")==0){
					exc[1][strlen(exc[1]) - 1] = '\0';
					strcat(root_folder,"/ls");
					execv(root_folder,exc);
				}else if(strcmp(exc[0],"date")==0){
						exc[1][strlen(exc[1]) - 1] = '\0';
						strcat(root_folder,"/date");
						execv(root_folder,exc);
				}else if(strcmp(exc[0],"mkdir")==0){
					if(j==2){
						exc[1][strlen(exc[1]) - 1] = '\0';
						strcat(root_folder,"/mkdir");
						execv(root_folder,exc);
					}else if(j==3){
						exc[2][strlen(exc[2]) - 1] = '\0';
						strcat(root_folder,"/mkdir");
						execv(root_folder,exc);
					}
				}else if(strcmp(exc[0],"cat")==0){
					if(j==2){
						exc[1][strlen(exc[1]) - 1] = '\0';
						strcat(root_folder,"/cat");
						execv(root_folder,exc);
					}else if(j==3){
						exc[2][strlen(exc[2]) - 1] = '\0';
						strcat(root_folder,"/cat");
						execv(root_folder,exc);
					}
				}else if(strcmp(exc[0],"rm")==0){
					if(j==2){
						exc[1][strlen(exc[1]) - 1] = '\0';
						strcat(root_folder,"/rm");
						execv(root_folder,exc);
					}else if(j==3){
						exc[2][strlen(exc[2]) - 1] = '\0';
						strcat(root_folder,"/rm");
						execv(root_folder,exc);
					}
				}
		}
		exit(0);
		}else{
			wait(NULL);
		}
		}


		
	
	}
}
	

