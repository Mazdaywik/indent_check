#include <stddef.h>
int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    size_t i, maxi = 0;
    for (i = 1; i < nel; i++) {
        if (compare((char*)base + i * width, (char*)base + maxi * width) > 0) {
            maxi = i;
        }
    }
    return maxi;
}