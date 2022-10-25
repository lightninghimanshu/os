#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
typedef struct __myarg_t {
int a;
int b;
} myarg_t;

 typedef struct __myret_t {
 int x;
 int y;
 } myret_t;

 void *mythread(void *arg) {
   char * r = (char* )arg;
   printf("%s",r);
   // system(r);
 }

 int main(int argc, char *argv[]) {
    int rc;
    pthread_t p;
   //  myret_t *m;

   //  myarg_t args;
   //  args.a = 10;
   //  args.b = 20;
    char *arr="./scandir -a";
    pthread_create(&p, NULL, mythread, arr);
    pthread_join(p, NULL);
   //  printf("returned %d %d\n", m->x, m->y);
    return 0;
}