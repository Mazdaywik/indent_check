#include <stdlib.h>
int maxarray(void *base, size_t nel, size_t width,
                int (*compare)(void *a, void *b))
{
    char *max = base;
    char *begin = base;
    begin += width;
    int n=0;
    for(size_t i = 1; i < nel; ++i)
    {
        if (compare(begin, max) > 0) {
            max = begin;
            n = i;
        }
        begin += width;
    }
    return n;
}