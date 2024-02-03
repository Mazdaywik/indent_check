#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int less(unsigned long i, unsigned long j){
    if(a[i] < a[j]) return 1;
    return 0;
}

unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j)){
            if(nel == 1){
                return 0;
            }
            for(unsigned long i = 0; i < nel; i++){
                if(i == 0){
                    if(less(i, i+1) == 0){
                        return i;
                    }
                }
                else{
                    if(i == nel - 1){
                        if(less(i, i - 1) == 0){
                            return i;
                        }
                    }
                    else{
                        if(less(i, i-1) == 0 && less(i, i + 1) == 0){
                            return i;
                        }
                    }
                }  
            }
        }
