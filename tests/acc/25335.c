#include <stdio.h>
int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    char *start=(char*)base;
    int max_index=0;
    for (size_t i=1; i<nel; i++) if (compare (start+width*i, start +width*max_index)>0) max_index=i;
    return max_index;
}