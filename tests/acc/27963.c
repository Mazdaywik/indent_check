#include <stdio.h>

int maxarray(void *base, size_t nel, size_t width,
        int (*compare)(void *a, void *b))
{
    int indexMaxVal = 0; 
    char *maxVal = (char*) base;
    char *val = (char*)  base;

    for (size_t i = 1; i < nel; ++i)
    {
        val += width;

        if (compare(maxVal, val) < 0) 
        {
            indexMaxVal = i; 
            maxVal = val;   
        }
    }

    return indexMaxVal; 
}
