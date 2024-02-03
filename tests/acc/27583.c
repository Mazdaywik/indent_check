#include <stdio.h>
#include <string.h> 

int maxarray(void *base, size_t nel, size_t width,
             int (*compare)(const void *a, const void *b)) {
    char *p = base;
    char *max = p; 
    int num = 0;

    for (int i = 1; i < nel; i++) {
        if (compare(p + width * i, max) > 0) {
            max = p + width * i;
            num = i;
        }
    }

    return num; 
}
