#include <stdio.h>

int compare_int(void *a, void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    if (*x > *y) {
        return 1;
    } else if (*x < *y) {
        return -1;
    } else {
        return 0;
    }
}

int maxarray(void *base, size_t nel, size_t width,
    int (*compare)(void *a, void *b))
{
    char *array = (char *)base;
    int mindex = 0;
    size_t i = 1;
    while (i < nel){
        char *element = array + i * width;
        char *max_element = array + mindex * width;
        if (compare(element, max_element) > 0) {
                mindex = i;
            }
        i += 1;
    }
    
    return mindex;
}
