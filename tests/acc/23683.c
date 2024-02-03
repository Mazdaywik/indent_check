#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width)
{   
    void *array = malloc(nel*width);

    for (size_t i = 0; i < nel; i++)
    {
        memcpy((void*) ((size_t) array + i * width), (void*)((size_t)base + i * width), width);
    }
    
    for (size_t i = 0; i < nel; i++)
    {
        memcpy((void*)((size_t)base + i * width), (void*)((size_t)array + nel * width - (i+1) * width), width);
    }
    free(array);
}