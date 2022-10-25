#include<stdio.h>
#include<time.h>

int main()
{
    // printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");

    time_t t;   // not a primitive datatype
    time(&t);

    printf("%s", ctime(&t));

    // printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}