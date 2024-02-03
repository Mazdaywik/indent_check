#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width)
{
    char *p = base;
    char cache[width];
    for (size_t i = 0; i < nel / 2; i++)
    {
        size_t j = nel - i - 1;
        memcpy(cache, p + i * width, width);
        memcpy(p + i * width, p + j * width, width);
        memcpy(p + j * width, cache, width);
    }
}