#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapBytes(char *a, char *b, size_t width) {
    for (size_t i = 0; i < width; ++i) {
        char temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void revarray(void *base, size_t nel, size_t width)
{
        char *left = (char *)base;
        char *right = (char *)base + (nel - 1)*width;
        for (int i = 0; i < nel/2; i++) {
            swapBytes(left, right, width);
            left += width;
            right -= width;
        }
}