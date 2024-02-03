#include <stdio.h>

void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j)) 
{
    int f=0;
    for(int i=1;i<nel;i++)
    if(compare(i-1,i)==1) 
    swap(i-1,i);
    for(int i=nel-1;i>=1;i--)
    if(compare(i-1,i)==1)
    {
        swap(i-1,i),f=1;
    }
    if(f) 
    bubblesort(nel,compare,swap);
}

int array[] = {2, 3, 10, 5, 9, 1, 4};
const size_t ARR_SZ = sizeof(array) / sizeof(array[0]);

int compare(unsigned long i, unsigned long j) 
{
    if (array[i]==array[j]) 
        return 0;
    else if (array[i] < array[j]) 
        return -1;
    else
        return 1;
}

void swap(unsigned long i, unsigned long j) 
{
    int t=array[i];
    array[i]=array[j];
    array[j]=t;
}

int main() 
{
    bubblesort(ARR_SZ, compare, swap);
    for (size_t i = 0; i < ARR_SZ; ++i) 
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}