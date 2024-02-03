#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
long long f(int n){
    if (n == 1){
        return 1;
    }
    if (n == 0){
        return 0;
    }
    return f(n - 1) + f(n - 2);
}

void shellsort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)){
    int count = 0;
    long long t;
    while (f(count) < nel){
        count += 1;
    }
    count -= 1;
    int i, elem, loc, k;
    while (count > 0){
        t = f(count);
        i = t;
        while (i < nel){
            loc = i;
            while ((loc >= t) && compare(loc - t, loc) > 0){
                swap(loc - t, loc);
                loc -= t;
            }
            i += 1;
        }
        count -= 1;
    }
}