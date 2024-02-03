#include <stdio.h>
int maxarray(void *base, size_t nel, size_t width,
        int (*compare)(void *a, void *b)) {
    int maxIndex = 0;
    char * max = (char *)base;

    for (int i = 1; i < nel; i++) {
        char *current = (char *)base + i * width;
        if (compare(current, max) > 0) {
            max = current;
            maxIndex = i;
        }
    }
    return maxIndex;
}