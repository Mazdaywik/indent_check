#include <stddef.h>
#include <stdio.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    if (base == NULL || nel == 0 || width == 0 || compare == NULL) {
        return -1;
    }

    char *ptr = (char *)base;

    size_t max_index = 0;

    for (size_t i = 1; i < nel; ++i) {
        if (compare(ptr + i * width, ptr + max_index * width) > 0) {
            max_index = i;
        }
    }

    return (int)max_index;
}