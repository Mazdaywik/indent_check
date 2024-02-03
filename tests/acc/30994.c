#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width)
{
    if (base == NULL || nel == 0 || width == 0)
        return;
    void *t = malloc(width);
    if (t == NULL)
        return;
    for (size_t i = 0; i < nel / 2; ++i)
    {
        size_t j = nel - i - 1;
        memcpy(t, (char *)base + i * width, width);
        memcpy((char *)base + i * width, (char *)base + j * width, width);
        memcpy((char *)base + j * width, t, width);
    }
    free(t);
}