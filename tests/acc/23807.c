#include <stdio.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width)
{
    char help[width];
    for (size_t i = 0; i < nel/2; i++) {
        memmove(help, ((char*)base + i * width), width);
        memmove(((char*)base + i * width), ((char*)base + (nel - i -1) * width), width);
        memmove(((char*)base + (nel - i -1)  * width), help, width);
    }
}