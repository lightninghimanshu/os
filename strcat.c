#include <stdio.h>
#include <string.h>

int main(){
    char *a ="a";
    char *b ="./cat";
    char c[10000];
    strcpy(c,b);
    strcat(c," l");
    printf("%s\n",c);
}