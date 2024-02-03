#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void revarray(void *base, size_t nel, size_t width)
{
    void *ls = malloc(width);
    for (int i = 0; i < (nel / 2); i++)
    {
        char *lefts = (char*)base + i * width, *rights = (char*)base + (nel - i - 1) * width;

        memcpy(ls,     lefts,  width);
        memcpy(lefts,  rights, width);
        memcpy(rights, ls,     width);
    }

    free(ls);
}