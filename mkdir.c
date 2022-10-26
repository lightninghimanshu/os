#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mkdirm(char file[],int mode){
    mkdir(file,mode);
}

void mkdirv(char file[]){
    mkdir(file,0777);
    printf("%s created\n",file);
}
void mkdircmd(char file[]){
    mkdir(file,0777);
}
int main(int argc, char *argv[]){
    char *original = malloc(sizeof( char) *10000);
    strcpy(original,argv[1]);
    char * token = strtok(argv[1], " ");
    token=strtok(NULL, " ");
    char * flag=token;
    int mflag=0;
    if (flag[0]=='-' && flag[1]=='m'){
        // token=original;
        flag=strtok(flag,"=");
        flag=strtok(NULL,"=");
        mflag=1;
        token = strtok(original," ");
        token = strtok(NULL," ");
        token = strtok(NULL," ");
    }
    while(token!=NULL){
        if (token==NULL){
            continue;
        }
        if (mflag==1){
            int mval = atoi(flag);
            if (flag[0]!='0' && mval==0){
                printf("Wrong mode");
            }
            else{
                mkdirm(token, atoi(flag));
            }
        }
        else if (strcmp(flag,"-v")==0){
            token=strtok(NULL, " ");
            mkdirv(token);
        }
        else if (flag[0]=='-'){
    		printf("Wrong Flag\n");
            return 1;
	    } 
        else{
            mkdircmd(token);
        }
        token=strtok(NULL, " ");

    }

}

