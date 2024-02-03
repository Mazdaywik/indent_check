#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width) {
    void * temp = (void *)malloc(width);

    for (int l = 0, r = nel - 1; l < r; ++l, --r) {
        memcpy(temp, (void*)((size_t)base+width*l), width);
        memcpy((void*)((size_t)base+width*l), (void*)((size_t)base+width*r), width);
        memcpy((void*)((size_t)base+width*r), temp, width);
    }

    free(temp);
}