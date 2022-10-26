#include <stdio.h>
#include <unistd.h>
#include <string.h>
void rmi(char arg[]){
    char c[10];
    printf("Do you want to delete %s?\n",arg);
    fgets(c,10,stdin);
    if (strcmp(c,"yes\n")==0){
        int valid = remove(arg);
        if (valid!=0){
            printf("Operation Unsuccessful: %s\n",arg);
        }
    }
}

void rmd(char arg[]){
    int valid = rmdir(arg);
    if (valid!=0){
        printf("Operation Unsuccessful: %s\n",arg);
    }
}

void rm(char arg[]){
    int valid = remove(arg);
    if (valid!=0){
        printf("Operation Unsuccessful: %s\n",arg);
    }
}
int main(int argc, char *argv[]){
    char * token = strtok(argv[1], " ");
    token=strtok(NULL, " ");
    char * flag=token;
    while(token!=NULL){
        if (token==NULL){
            printf("Less arguments\n");
            continue;
        }
        if (strcmp(flag,"-d")==0){
            token=strtok(NULL, " ");
            if (token==NULL){
                continue;
            }
            rmd(token);
        }
        else if (strcmp(flag,"-i")==0){
            token=strtok(NULL, " ");
            if (token==NULL){
                continue;
            }            
            rmi(token);
        }
       	else if (flag[0]=='-'){
    		printf("Wrong Flag\n");
            return 1;
	    } 
        else{
            token=strtok(NULL, " ");
            if (token==NULL){
                continue;
            }
            rm(token);
        }
    }
}

