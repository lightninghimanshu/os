#include <stdio.h>
#include <unistd.h>
#include <string.h>
void rmi(char arg[]){
    char c[10];
    printf("Do you want to delete %s?\n",arg);
    fgets(c,10,stdin);
    if (strcmp(c,"yes\n")==0){
        remove(arg);
    }
}

void rmd(char arg[]){
    rmdir(arg);
}

void rm(char arg[]){
    remove(arg);
}
int main(int argc, char *argv[]){
    char * token = strtok(argv[1], " ");
    token=strtok(NULL, " ");
    char * flag=token;
    while(token!=NULL){
        token=strtok(NULL, " ");
        if (token==NULL){
            continue;
        }
        if (strcmp(flag,"-d")==0){
        rmd(token);
        }
        else if (strcmp(flag,"-i")==0){
        rmi(token);
        }
        else{
        rm(token);
        }
    }
}

