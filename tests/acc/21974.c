#include <stddef.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    int max_index = 0;
    char *b = (char*)base;
    for (size_t i = 1; i < nel; i++) {
        if (compare(b + i*width, b + max_index*width) > 0) {
            max_index = i;
        }
    }
    return max_index;
}