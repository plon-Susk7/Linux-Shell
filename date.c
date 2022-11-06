#include<stdio.h>
#include<time.h>
#include<string.h>


int main(int argc,char* argv[]){
	time_t Time;
	struct tm* tm;
	char temp[100];
	time(&Time);
	tm = localtime(&Time);
	if(argc==1){
		
		strftime(temp, 100, "%a %d %b %Y %T\n", tm);
		printf("%s",temp);
	}else{
		if(strcmp(argv[1],"-I")==0){
		//prints date only
		strftime(temp, 50, "%Y-%m-%d\n", tm);
		printf("%s",temp);
		}else if(strcmp(argv[1],"-T")==0){
			//prints time in 24hr format
			strftime(temp,50,"%T\n",tm);
			printf("%s",temp); 	
		}
	}

	

}