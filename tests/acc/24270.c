#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void shellsort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)) { 
    if (nel == 1) {
        return;
    }
    int a = 1, b = 1;
    while (b <= nel) {
        b += a;
        a = b - a;
    }
    a = b - a;
    b = b - a;
    while (a != 0) {
        for (int i = b; i < nel; i += b) {
            int j = i - b;
            while (j >= 0 && compare(j, j + b) == 1) {
                swap(j, j + b);
                j -= b;
            }
        }
        a = b - a;
        b = b - a;
    }
}