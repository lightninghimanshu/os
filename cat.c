// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main()
{
	FILE* ptr;
	char ch;

	// Opening file in reading mode
	ptr = fopen("scandir.c", "r");

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

	// Closing the file
	fclose(ptr);
	return 0;
}
