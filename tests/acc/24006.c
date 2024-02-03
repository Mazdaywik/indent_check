#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width)
{
    if (base == NULL || nel <= 1 || width == 0) {
        return;
    }

    char *left = (char *)base;
    char *right = left + (nel - 1) * width;
    while (left < right) {
        for (size_t i = 0; i < width; i++) {
            left[i] ^= right[i];
            right[i] ^= left[i];
            left[i] ^= right[i];
        }
        left += width;
        right -= width;
    }
}