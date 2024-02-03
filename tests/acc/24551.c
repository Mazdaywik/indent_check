#include <stdio.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b))
{
 int maxi = 0;
 char* p;
 p = base;

 for (int i = 0; i < nel; i++)
 {
    if (compare(p + width*maxi, p + width*i) <= 0) 
    {
        maxi = i;
    }
 }

 return maxi;
}