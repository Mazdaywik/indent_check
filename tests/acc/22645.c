#include <stdio.h>
#include <stddef.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width) {
    char *low = (char *)base;
    char *high = (char *)base + (nel - 1) * width;

    while (low < high) {
        char temp[width];
        memcpy(temp, low, width);
        memcpy(low, high, width);
        memcpy(high, temp, width);

        low += width;
        high -= width;
      }
}
