#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width){
    for(int i = 0; i < nel / 2; i ++){
        void *tmp = malloc(width);
        memcpy(tmp, ((char*)base + i*width), width);
        memcpy(((char*)base + i*width), ((char*)base + (nel - i - 1)*width), width);
        memcpy(((char*)base + (nel - i - 1)*width), tmp, width);
        free(tmp);
    }
}