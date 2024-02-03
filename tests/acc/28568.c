#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)){
    int is_i_bigger = 0, max1 = 0;
    for (int i = 0; i < nel; i++){
        is_i_bigger = compare(i * width + (char*) base, max1 * width + (char*) base);
        if (is_i_bigger > 0) max1 = i;
    }
    return max1;
}