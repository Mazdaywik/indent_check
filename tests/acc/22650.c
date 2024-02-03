#include <stdio.h>
#include <stddef.h>
#include <string.h>

int compare(void* a, void* b) {
    int* x = (int*) a;
    int* y = (int*) b;
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    return 0;
}

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    if (nel == 0) {
        return -1;
    }

    char *max_element = (char *)base;
    size_t max_index = 0;

    for (size_t i = 1; i < nel; i++) {
        char *current = (char *)base + i * width;
        if (compare(current, max_element) > 0) {
            max_element = current;
            max_index = i;
        }
    }

    return (int)max_index;
}
