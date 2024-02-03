#include <stdio.h>

void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    int l = 0;
    int r = nel - 1;
    for(unsigned long i = 0; i < nel; i++){
        if (i % 2 == 0){
            for(unsigned long j = l; j < r; j++){
                if(compare(j, j + 1) > 0) 
                    swap(j , j + 1); 
            }
            r--;
        }
        else{
            for(unsigned long j = r; j > l; j--){
                if(compare(j - 1, j ) > 0) 
                    swap(j - 1 , j); 
            }
            l++;
        }
    }
}