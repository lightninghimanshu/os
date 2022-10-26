#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lsa(char arg[]){
    struct dirent **list;
    int n;
    char dot='.';
    if (arg==NULL){
        n = scandir(".", &list, NULL, alphasort);
    }else{
        n = scandir(arg, &list, NULL, alphasort);
    }
    if (n == -1) {
        exit(EXIT_FAILURE);
    }
    while (n--) {
        printf("%s\n", (list[n]->d_name));
        free(list[n]);

    }
    free(list);

    exit(EXIT_SUCCESS);
}
void ls(char arg[]){
    struct dirent **list;
    int n;
    char dot='.';
    if (arg==NULL){
        n = scandir(".", &list, NULL, alphasort);
    }else{
        n = scandir(arg, &list, NULL, alphasort);
    }    if (n == -1) {
        exit(EXIT_FAILURE);
    }

    while (n--) {

        if((list[n]->d_name)[0]!=dot){
            printf("%s\n", list[n]->d_name);
            free(list[n]);
        }
    }
    free(list);

    exit(EXIT_SUCCESS);
}

void lsd(char arg[]){
    struct dirent **list;
    int n;
    char dot='.';
    if (arg==NULL){
        n = scandir(".", &list, NULL, alphasort);
    }else{
        n = scandir(arg, &list, NULL, alphasort);
    }    if (n == -1) {
        exit(EXIT_FAILURE);
    }
    while (n--) {
        if (n==0){
            printf("%s\n", list[n]->d_name);
            free(list[n]);
        }

    }
    free(list);

    exit(EXIT_SUCCESS);
}



int main(int argc, char *argv[]){
    if (argv[1]==NULL){
        ls(NULL);
    }
    else if (strcmp(argv[1],"-a")==0){
        lsa(argv[2]);
    }
    else if (strcmp(argv[1],"-d")==0){
        lsd(argv[2]);
    }
    else if (argv[1][0]=='-'){
		printf("Wrong Flag\n");
	}    
    else{
        ls(argv[1]);
    }
}