#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t *get(uint8_t *base, size_t ind, size_t width){
    return base + width*ind;
}

void give(uint8_t *first, uint8_t *second, size_t width){
    for (int b = 0; b < width; b++)
        *(first + b) = *(second + b);
}

void swap(uint8_t *base, size_t first, size_t second, size_t width){
    uint8_t *temp = malloc(sizeof(uint8_t) * width);
    give(temp, get(base, first, width), width);
    give(get(base, first, width), get(base, second, width), width);
    give(get(base, second, width), temp, width);
    free(temp);
}

void revarray(void *base, size_t nel, size_t width)
{
    size_t indLeft = 0, indRight = nel - 1;
    while (indLeft < indRight){
        swap(base, indLeft++, indRight--, width);
    }
}