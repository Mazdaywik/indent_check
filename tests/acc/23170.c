#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long k = 3;
unsigned long a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int compare(unsigned long i){
    if(a[i] < k){
        return -1;
    }
    if(a[i] > k){
        return 1;
    }
    return 0;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
    unsigned long minIndex = 0;
    unsigned long maxIndex = nel - 1;
    while(maxIndex >= minIndex){
        unsigned long midIndex = (minIndex + maxIndex) / 2;
        if(compare(midIndex) == 0){
            return midIndex;
        }
        if(compare(midIndex) == -1){
            minIndex = midIndex + 1;
        }
        else{
            maxIndex = midIndex - 1;
        }
    }
    return nel;
}