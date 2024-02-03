#include <stddef.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    void *m = base;
    int ind = 0;
    char *k = base;
    for (size_t i = 0; i < nel; i++) {
        if (i == 0) {
            m = k;
        } else {
            k = k + width;
            if (0 > compare(m, k)) {
                m = k;
                ind = i;
            }
        }
    }
    return ind;
}