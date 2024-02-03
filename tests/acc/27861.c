#include <stdio.h>
#include <stdlib.h>

int maxarray(void *base, size_t nel, size_t width,
        int (*compare)(void *a, void *b))
{
    int max = 0;
    for (int i = 0; i < nel; i++)
    {
        if (compare((char*)base + i*width, (char*)base + max*width) > 0){
            max = i;
        }
    }
    return max;
}