#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int maxarray(void *base, size_t nel, size_t width,
        int(*compare)(void *a, void *b))
{
    uint8_t *p_max_elem = malloc(width);
    uint8_t *elem = base;
    int max_index = 0;
    memcpy(p_max_elem, base, width);
    for(int i = 1; i < nel; i++) {
        elem += width;
        int res = compare(elem, p_max_elem);
        if(res > 0) {
            max_index = i;
            memcpy(p_max_elem, elem, width);
        }
    }
    free(p_max_elem);
    return max_index;
}