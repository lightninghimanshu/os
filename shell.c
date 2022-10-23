#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAX_CHAR = 100;
int main(int argc, char *argv[])
{
	int mainflag=1;
	printf("Welcome to the shell\n");
	char command[MAX_CHAR];
	char exit[]="exit\n";
	while(mainflag==1){
		printf("$");
		fgets(command, MAX_CHAR, stdin);
		printf("%d\n",strlen(command));
		if(strcmp(command,exit)==0){
			mainflag=0;
			printf("bye");
		}
		else{
			system(command);
		}

	}
	return 0;

}