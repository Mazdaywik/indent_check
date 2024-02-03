#include <stdio.h>
#include <stdint.h>
int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b))
{
    int k=0;
    uint8_t* max=base;
    uint8_t* base1=base;
    for (; base1<=(uint8_t*)base+(nel-1)*width; base1+=width)
        if (compare(max,base1)<0)
{
            k=(base1-(uint8_t*)base)/width;
            max=base1;
}
    return k;
}