#include <stdio.h>
#include <stdint.h>

void revarray(void* base, size_t nel, size_t width)
{
    uint8_t* base1 = base;
    for (int i=0; i<nel/2; i++)
{
        for (int j=0; j<width; j++)
{
            uint8_t temp=*(base1+j+i*width);
            *(base1+j+i*width)=*(base1+j+(nel-1-i)*width);
            *(base1+j+(nel-1-i)*width)=temp;
}
}
}