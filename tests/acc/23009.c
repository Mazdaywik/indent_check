#include <stdio.h>
#include <stdint.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    void *max = base;
    int max_i = 0;
    int8_t *current = base;
    for (size_t i = 1; i < nel; ++i) {
        current+=width;
        if (compare(current, max) > 0){
            max = current;
            max_i = i;
        }
    }
    return max_i;
}