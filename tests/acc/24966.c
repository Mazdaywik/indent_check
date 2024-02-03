#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b))
{
    void *mx = malloc(width);
    memcpy(mx, base, width);
    int index = 0;

    //int *mx = ((int*)base + 0 * width), index = 0;

    for (int i = 1; i < nel; i++)
    {
        void *x = ((char*)base + i * width);
        if (compare(mx, x) < 0)
        {
            memcpy(mx, x, width);
            index = i; 
        }
    }
    free(mx);
    return index;
}