// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int catn(char arg[])
{
	FILE* ptr;
	char ch;

	// Opening file in reading mode
	ptr = fopen(arg, "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	printf("content of this file are \n");
    int i =1;
    char *c = "\n"  ;
	// Printing what is written in file
	// character by character using loop.
	do {
		ch = fgetc(ptr);
		if (ch=='\n' || i==1){
            printf("\n %d ",i);
            i++;
        }else{
        printf("%c", ch);
        }
		// Checking if character is not EOF.
		// If it is EOF stop eading.
	} while (ch != EOF);
	printf("\n");

	// Closing the file
	fclose(ptr);
	return 0;
}


int catE(char arg[])
{
	FILE* ptr;
	char ch;

	// Opening file in reading mode
	ptr = fopen(arg, "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	printf("content of this file are \n");
    char *c = "\n"  ;
	// Printing what is written in file
	// character by character using loop.
	do {
		ch = fgetc(ptr);
		if (ch=='\n'){
            printf("%c%c",'$',ch);
        }else{
        printf("%c", ch);
        }
		// Checking if character is not EOF.
		// If it is EOF stop eading.
	} while (ch != EOF);
	printf("\n");


	// Closing the file
	fclose(ptr);
	return 0;
}


int cat(char arg[])
{
	FILE* ptr;
	char ch;

	// Opening file in reading mode
	ptr = fopen(arg, "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	printf("content of this file are \n");
    char *c = "\n"  ;
	// Printing what is written in file
	// character by character using loop.
	do {
		
        printf("%c", ch);
		// Checking if character is not EOF.
		// If it is EOF stop eading.
	} while (ch != EOF);
	printf("\n");
	// Closing the file
	fclose(ptr);
	return 0;
}

int main(int argc, char *argv[]){
    if (argv[1]==NULL){
        cat(NULL);
    }
    else if (strcmp(argv[1],"-n")==0){
        catn(argv[2]);
    }
    else if (strcmp(argv[1],"-E")==0){
        catE(argv[2]);
    }
    else{
        cat(argv[1]);
    }
}