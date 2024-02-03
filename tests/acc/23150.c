#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(void *a, void *b){
    return *(char*)a - *(char*)b;
}

int maxarray(void *base, size_t nel, size_t width, 
        int (*compare)(void *a, void *b)){
            char *maxelem = (char*)base;
            int maxei = 0;
            for(int i = 0; i < nel; i++){
                void *a = ((char*)base + i * width);
                if(compare(a, maxelem) > 0){
                            maxelem = a;
                            maxei = i;
                        }
            }
            return maxei;
}