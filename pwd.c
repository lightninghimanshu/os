#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
   char cwd[PATH_MAX];
   if (realpath(".", cwd) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   return 0;
}
