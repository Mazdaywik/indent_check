#include <stdio.h>
#include <stdlib.h>
#define MAX_FIB_SZ 40

int arr[] = {2, 3, 10, 5, 9, 1, 4};
const size_t ARR_SZ = sizeof(arr) / sizeof(arr[0]);

int calcFib(long n, long* fib) 
{
    fib[0] = 1;
    fib[1] = 2;
    size_t index = 1;
    long next;
    while ((next = fib[index - 1] + fib[index]) < n) 
    {
        index++;
        fib[index] = next;
    }
    return index + 1;
}

int compare (unsigned long i, unsigned long j)
{
    if (arr[i]==arr[j]) 
        return 0;
    else if (arr[i] < arr[j]) 
        return -1;
    else
        return 1;
}

void swap(unsigned long i, unsigned long j)
{
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
 long fibs[MAX_FIB_SZ];
 int cnt=calcFib(nel, fibs);
     for(int i = cnt-1; i>=0; i--)
     {
        int d = fibs[i];
        for (int j = 0; j<nel; j++)
        {
            for (int k = j-d; k>=0 && compare(k,k+d)==1;k-=d)
                swap(k, k+d);
        }
    }
}

int main() 
{
    shellsort(ARR_SZ, compare, swap);
    for (size_t i = 0; i < ARR_SZ; ++i) 
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}