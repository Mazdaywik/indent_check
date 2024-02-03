#include <stddef.h>
void revarray(void *base, size_t nel, size_t width) {
    size_t i, j;
    char temp;
    char *pbase = (char *)base;
    for (i = 0; i < nel/2; i++) {
        for (j = 0; j < width; j++) {
            temp = *(pbase + i * width + j);
            *(pbase + i * width + j) = *(pbase + (nel - i - 1) * width + j);
            *(pbase + (nel - i - 1) * width + j) = temp;
        }
    } 

}