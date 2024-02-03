#include <stdio.h>
#include <stdint.h>

void revarray(void *base, size_t nel, size_t width)
{
    size_t left = 0, right = (nel - 1)*width;
    uint8_t *const_base = base;
    while(left<right){
        uint8_t temp = *(const_base + left);
        *(const_base + left) = *(const_base+right);
        *(const_base + right) = temp;
        left++;
        right = right + 1 - ((right + 1) % width == 0 ? 2 * width : 0);
    }
}