#include <stdlib.h>
#include <string.h>
void revarray(void *base, size_t nel, size_t width) {
    void *temp = malloc(width);
    char *start = (char *)base;
    char *end = (char *)base + (nel - 1) * width;
    while (start < end) {
        memcpy(temp, start, width);
        memcpy(start, end, width);
        memcpy(end, temp, width);
        start += width;
        end -= width;
    }
    free(temp);
}