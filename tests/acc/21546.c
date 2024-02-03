#include <stdio.h>

void revarray(void *base, size_t nel, size_t width){
    char elem;
    for(int i = 0; i < nel / 2; i++){
        for(int j = 0; j < width; j++){
            elem = *((char*)base + i * width + j);
            *((char*)base + i * width + j) = *((char*)base + (nel - i - 1) * width + j);
            *((char*)base + (nel - i - 1) * width + j) = elem;
        }
    }
}