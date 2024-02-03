#include <stdio.h>
#include <stdlib.h>

typedef unsigned long lu;

int fib(lu number, int* array) {
    if (array[number] != 0) return array[number];
    else return fib(number - 1, array) + fib(number - 2, array);
}

lu find_d(lu nel, int *array) {

    lu ind = 0;

    for (lu i = 3; i < nel; i++) {
        array[i] = fib(i, array);
        if (array[i] >= nel) break;
        else ind = i;
    }
    return ind;
}

void shellsort(lu nel, 
    int (*compare)(lu i, lu j), 
    void (*swap)(lu i, lu j)) {
    
    if (nel == 0 || nel == 1) return;

    int* fibarr = (int*)calloc(sizeof(int), nel);
    fibarr[1] = fibarr[2] = 1;

    lu ind_d = find_d(nel, fibarr);
    
    for (lu index = ind_d - 1; index > 0; --index) {
        lu d = fibarr[index];
        //printf("this is d now: %lu\n", d);
        for (lu i = d; i < nel; ++i) {
            long k = i - d;
            //printf("comparing el with ind %lu to el with ind %ld\n", i, k);
            while ((k >= 0) && compare(k + d, k) < 0) {
                swap(k + d, k);
                //printf("swapped\n");
                k -= d;
                //printf("k after swap %ld\n", k);
            }
        }
    }
    free(fibarr);
}
