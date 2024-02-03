#include <string.h>
#include <stdlib.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    if (nel == 1)
        return 0;

    void *el = malloc(width),
         *max = malloc(width);
    memcpy(max, base, width);

    int index = 0;
    for (size_t i = 0; i < nel; ++i) {
        memcpy(el, (void*)((size_t)base+i*width), width);
        if (compare(el, max) > 0) {
            memcpy(max, el, width);
            index = (int)i;
        }
    }

    free(el);
    free(max);

    return index;
}