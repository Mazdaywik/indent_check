#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void revarray(void *base, size_t nel, size_t width)
{
    for (int i = 0; i < nel/2; i++){
        for (int j = 0; j < width; j++){
            char *left = ((char*)base + j + i * width);
            char *right = ((char*)base + j + (nel - i - 1) * width);
            char t = *left;
            *left = *right;
            *right = t;
        }
    }
}