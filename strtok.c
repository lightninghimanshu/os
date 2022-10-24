#include<stdio.h>
#include <string.h>

int main() {   
   char string[50] = "Hello! We";
   // Extract the first token
   
   // loop through the string to extract all other tokens
      printf( " %s\n", token ); //printing each token
      token = strtok(NULL, " ");
      printf( " %s\n", token ); //printing each token
      token = strtok(NULL, " ");
      printf( " %s\n", token ); //printing each token
      token = strtok(NULL, " ");
  return 0;
}