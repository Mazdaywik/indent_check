#include <stdio.h>

void revarray(void *base, size_t nel, size_t width) {
    int i, j;
    unsigned char *a;
    unsigned char *b;
    unsigned char c;

    for (j = 0; j < width; j++) {
        for (i = 0; i < nel / 2; i++) {
            a = ((char *)base + i * width + j);
            b = ((char *)base + (nel - i - 1) * width + j);
            c = *a;
            *a = *b;
            *b = c;
        }
    }
}