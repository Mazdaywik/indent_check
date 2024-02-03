#include <stdio.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)){
    int i_max = 0;
    for(int i = 1; i < nel; i++){
        if(compare(((char*)base + i * width), ((char*)base + i_max * width)) > 0){
            i_max = i;
        }
    }
    return i_max;
}