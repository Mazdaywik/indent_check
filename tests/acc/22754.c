#include <stddef.h>

void revarray(void *base, size_t nel, size_t width) {
    char *start = (char *)base;
    char *end = start + (nel-1) * width;
    char t;

    for (size_t i = 0; i < nel / 2; i++) {
        for (size_t j = 0; j < width; j++) {
            t = *(start+j);
            *(start+j) = *(end+j);
            *(end + j) = t;
        }

        start += width;
        end -= width;
    }
}