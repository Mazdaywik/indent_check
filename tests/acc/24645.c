#include<stdio.h>

void revarray(void *base, size_t nel, size_t width){
        int i;
        char *start = (char *)base;
        char *end = start + (nel + 1) * width;
        while(end - start > width){
                end -= width * 2;  
                for(i = 0;i < width;i++){
                        int t = *start;
                        *start = *end;
                        *end = t;
                        start++;
                        end++;
                }
        }
}
