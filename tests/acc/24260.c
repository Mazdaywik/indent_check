#include <stdlib.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    size_t max_ind = 0;
    for (size_t i = 1; i < nel; i++) {
        char *a = (char *)base + max_ind * width;
        char *b = (char *)base + i * width;
        if (compare(a, b) < 0) {
            max_ind = i;
        }
    }
    return max_ind;
}