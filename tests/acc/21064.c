#include <stdio.h>
#include <stdint.h>

void *get(void *base, size_t ind, size_t width){
    return (uint8_t*) base + width*ind;
}

int maxarray(void *base, size_t nel, size_t width,
             int (*compare)(void *a, void *b))
{
    int indMax = 0;
    for(size_t ind = 1; ind < nel; ind++){
        if(compare(get(base, ind, width), get(base, indMax, width)) >= 1){
            indMax = ind;
        }
    }
    return indMax;
}