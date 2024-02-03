#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width) {
    if (nel <= 1)
        return;
    void *temp = malloc(width * nel);
    unsigned char *baseBytes = (unsigned char*)base;
    unsigned char *tempBytes = (unsigned char*)temp;
    for (size_t i = 0; i < nel; i++)
        memcpy(tempBytes + i * width, baseBytes + (nel - 1 - i) * width, width);
    memcpy(base, temp, width * nel);
    free(temp);
}