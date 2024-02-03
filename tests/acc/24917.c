#include <stdlib.h>
void revarray(void *base, size_t nel, size_t width)
{
    //char *bbegin = base;
    char *end1 = (char*)base;
    size_t i=0;
    while (i < nel - 1) {
        end1 += width;
        i += 1;
    }

    char *begin = (char*)base;
    while (begin < end1) {
        char r;
     
        for (size_t y=0; y<width; y++) {
            r = *(char*)begin;
            *(char*)begin = *end1;
            *end1 = r;
            begin += 1;
            end1 += 1;
        }
        end1 -= width*2;
    }
}