#include <stdio.h>
void revarray(void *base, size_t nel, size_t width)
{
char *start = base;
char *end = start + (nel - 1) * width;


while (start < end) {
    size_t i;
    
    for (i = 0; i < width; i++) {
        char temp = start[i];
        start[i] = end[i];
        end[i] = temp;
    }
    
    start += width;
    end -= width;
}
}