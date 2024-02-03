#include <stdio.h>#include <stdlib.h>
int maxarray(void *base, unsigned long nel, unsigned long width, int (*compare)(void *a, void *b))
{ int num=0;
    for(int i=1; i<nel; i++) {if (compare((char *)base + num*width, (char *)base + i*width)<0) num=i;}
   return num;}
int compare(void  *a, void  *b)
{if (*(int*)a>*(int*)b) return 1; else{
            if (*(int*)a==*(int*)b) return 0; else return -1;}}

int main(int argc, char  **argv)
{
    int array[5]={1,2,3,5,4};
        printf("%d\n", maxarray(array, 5, sizeof(int), compare));
}
