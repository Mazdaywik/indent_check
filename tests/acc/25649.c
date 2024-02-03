#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int compare(unsigned long i, unsigned long j) {
    if (i < j) return -1;
    else if (i > j) return 1;
    else return 0;
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    if (nel == 1) return;
    int a = 1;
    int b = 1;
    int ld = 0;
    while (b < nel){
        int c = b;
        b += a;
        a = c;
        ld++;
    }
    int *d;
    d = (int*)malloc(sizeof(int) * ld);
    a = 1;
    b = 1;
    for (int i = 0; b < nel; i++) {
        int c = b;
        b = a + b;
        a = c;
        d[i] = a;
    }
    int k = ld - 1;
    while (k >= 0){
        for (int i = 0; i < nel; i++){
            int loc = i - d[k]; 
            while (loc >= 0 && compare(loc, loc + d[k]) == 1){
                swap(loc, loc + d[k]);
                loc-= d[k];
            }
        }
        k--;
    }
    free(d);
}
