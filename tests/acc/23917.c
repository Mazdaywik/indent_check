#include <stdio.h>


void revarray(void *base, size_t nel, size_t width){
    char *start = (char *)base;
    char *end = (char *)base + (nel - 1) * width;
    char temp;

    while (start < end) {
        for (size_t i = 0; i < width; i++) {
            temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end++;
        }
        end -= 2 * width;
    }
}