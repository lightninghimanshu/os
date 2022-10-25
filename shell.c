#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int MAX_CHAR = 100;

void cdP_cmd(){
	char * token = strtok(NULL, " ");
	chdir(token);
}

void cdL_cmd(){
	char * token = strtok(NULL, " ");
	chdir(token);
}

void cd_cmd(){
	char * token = strtok(NULL, " ");
	if (token == NULL){
	return;
	}
	if (strcmp(token,"-P")==0){
		cdP_cmd();
	}
	else if(strcmp(token,"-L")==0){
		cdP_cmd();
	}
	else{
		char * token = strtok(NULL, " ");
		chdir(token);
	}
}

void echoN_cmd(){
	char * token = strtok(NULL, " ");
	printf("%s",token);
}

void echoHelp_cmd(){
	printf("%s\n","Echo help");
}

void echo_cmd(){
	char * token = strtok(NULL, " ");
	if (token == NULL){
		return;
	}
	if (strcmp(token,"-n")==0){
		echoN_cmd();
	}
	else if(strcmp(token,"--help")==0){
		echoHelp_cmd();
	}
	else {
		printf("%s\n",token);

	}
	
}

void pwdP_cmd(){
	char s[100];
	getcwd(s,100);
	printf("P%s\n",s);
}

void pwdL_cmd(){
	char s[100];
	realpath(".", s);
	printf("L%s\n",s);
}

void pwd_cmd(){
	char * token = strtok(NULL, " ");
	if (token == NULL){
		char s[100];
		getcwd(s,100);
		printf("%s\n",s);
		return;
	}
	if (strcmp(token,"-P")==0){
		pwdP_cmd();
	}
	else if(strcmp(token,"-L")==0){
		pwdL_cmd();
	}
	else{
		printf("Not Supported");
	}
}

int main(int argc, char *argv[])
{
	int mainflag=1;
	// system("clear");
	printf("Welcome to the shell\n");
	char command[MAX_CHAR];
	char * original = malloc(sizeof(char)*MAX_CHAR);
	char * token;
	char cmdexit[]="exit";
	char cmdcd[]="cd";
	char cmdecho[]="echo";
	char cmdpwd[]="pwd";

	char cmdls[]="ls";
	char cmdcat[]="cat";
	char cmdrm[]="rm";
	char cmdmkdir[]="mkdir";
	
	char cmdclear[]="clear";

	while(mainflag==1){
		printf("$");
		fgets(command, MAX_CHAR, stdin);
		// printf("!");
		command[strcspn(command, "\n")] = 0;
		strcpy(original,command);
		char * token = strtok(command, " ");
		if(strcmp(token,cmdexit)==0){
			mainflag=0;
			printf("bye");
		}
		if(strcmp(token,cmdcd)==0){
			cd_cmd(token);
		}
		if(strcmp(token,cmdecho)==0){
			echo_cmd(token);
		}
		if(strcmp(token,cmdpwd)==0){
			pwd_cmd(token);
		}
		else{
			int flag=0;
			char *arg = NULL;
			char *arg2 = NULL;
			char *binaryPath = "./scandir";
			if (strcmp(token,cmdls)==0){
				binaryPath = "./scandir";
				token = strtok(NULL, " ");
				arg=token;
				token = strtok(NULL, " ");
				arg2=token;
				flag=1;
				
			}
			else if (strcmp(token,cmdcat)==0){
				binaryPath="./cat";
				token = strtok(NULL, " ");
				arg=token;
				token = strtok(NULL, " ");
				arg2=token;
				flag=1;
			}
			else if (strcmp(token,cmdrm)==0){
				binaryPath = "./remove";
				arg=original;
				flag=1;
			}
			else if (strcmp(token,cmdmkdir)==0){
				binaryPath = "./mkdir";
				arg=original;
				flag=1;
			}
			else if (strcmp(token,cmdclear)==0){
				system("clear");
			}			if (flag==1){
				int rc = fork();
				if (rc < 0) { 
					exit(1);
				} else if (rc == 0) { 
					char *args[] = {binaryPath, arg, arg2, NULL};
					execve(binaryPath, args, NULL);   
					printf("this shouldn’t print out");
				} else { 
					int wc = wait(NULL);
					flag=0;
				}
			}
			
		}

	}
	return 0;

}