#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)){
    int ans = 0;
    for (int i = 1; i < nel; i++) {
        char *a = (char*)base + ans * width;
        char *b = (char*)base + i * width;
        if (compare(b, a) > 0) {
            ans = i;
        }
    }
    return ans;
}