#include <stddef.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    if (base == NULL || nel == 0 || width == 0 || compare == NULL) {
        return -1;
    }

    char *ptr = (char *)base;
    size_t maxind = 0;

    for (size_t i = 1; i < nel; ++i) {
        char *c = ptr + i * width;
        char *maxelem = ptr + maxind * width;

        if (compare(c, maxelem) > 0) {
            maxind = i;
        }
    }

    return (int)maxind;
}
