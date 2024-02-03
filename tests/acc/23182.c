#include <stdio.h>
int maxarray(void *base, size_t nel, size_t width,
        int (*compare)(void *a, void *b))
{
    int mx, res;
    mx = 0;
    for (int i = 1; i < nel; i++) {
        res = (compare ((char*)base + mx*width, (char*)base + i*width)); 
        if (res<0) {
		mx=i;
	}
    }
    return mx;
}