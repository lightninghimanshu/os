#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int catn(char arg[])
{
	FILE* ptr;
	char ch;

	ptr = fopen(arg, "r");

	if (NULL == ptr) {
		printf("File error\n");
	}

    int i =1;
    char *c = "\n"  ;
	while (ch != EOF){
		ch = fgetc(ptr);
		if (ch !=EOF){
			if (ch=='\n' || i==1){
				printf("\n %d ",i);
				i++;
			}else{
			printf("%c", ch);
			}
		}
	};
	printf("\n");

	fclose(ptr);
	return 0;
}


int catE(char arg[])
{
	FILE* ptr;
	char ch;

	ptr = fopen(arg, "r");

	if (NULL == ptr) {
		printf("File error\n");
	}

    char *c = "\n"  ;
	 while (ch != EOF)
	{
		ch = fgetc(ptr);
		if (ch !=EOF){
		if (ch=='\n'){
            printf("%c%c",'$',ch);
        }else{
        printf("%c", ch);
        }
	}
	}
	printf("\n");


	fclose(ptr);
	return 0;
}


int catcmd(char arg[])
{
	FILE* ptr;
	char ch;

	ptr = fopen(arg, "r");

	if (NULL == ptr) {
		printf("File error\n");
	}

	char *c = "\n"  ;
	while (ch != EOF){
		ch = fgetc(ptr);
		if (ch != EOF){
			printf("%c", ch);
			printf("\n");
		}		
	}
	fclose(ptr);
	return 0;
}

int main(int argc, char *argv[]){
    if (argv[1]==NULL){
        catcmd(NULL);
    }
    else
	if (strcmp(argv[1],"-n")==0){
        catn(argv[2]);
    }
    else if (strcmp(argv[1],"-E")==0){
        catE(argv[2]);
    }
	else if (argv[1][0]=='-'){
		printf("Wrong Flag\n");
	} 
    else{
        catcmd(argv[1]);
    }
}