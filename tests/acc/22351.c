#include <stdio.h>
#include <stddef.h>
#include <stdio.h> 
#include <stdint.h>
int maxarray(void *base, size_t nel, size_t width,
        int (*compare)(void *a, void *b)){
        size_t res = 0;
        char* k = (char*)base;
        char *n = k;
        for (size_t i = 1; i < nel; i++){
            char *m = (k + i*width);
            if (compare(n , m) < 0){
                //printf("%d", compare(n , m));
                res = i;
                n = m;
            } 
        }
        return(res);
}