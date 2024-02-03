#include <stdio.h>
#include <stdint.h>

void revarray(void *base, size_t nel, size_t width)
{
        uint8_t * left = base;
        uint8_t * right = (uint8_t*) base + (nel - 1)*width;

        while (left < right) {
            char tmp;
            for (size_t i = 0; i < width; i++) {
                tmp = *((char*) left + i);
                *((char*) left + i) = *((char*) right + i);
                *((char*) right + i) = tmp;
            }
            left += width;
            right -= width;
        }
}