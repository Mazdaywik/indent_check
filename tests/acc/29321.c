#include <stdio.h>

unsigned long fyb(unsigned long x)
{
    unsigned long f0 = 1, f1 = 1, i = 1, s;
    
    if (x == 0 || x == 1) f1 = 1;
    else {
        while (i < x) {
        s = f1 + f0;
        f0 = f1;
        f1 = s;
        i = i + 1;
        }
    }
    return f1;
}

unsigned long which(unsigned long x)
{
    unsigned long n, per = 0;
    
    for (n = 1; fyb(n) <= x; n++) {
        per = fyb(n);
    }
    return (n - 1);
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    int i = which(nel);
    for (; i > 0; i--) {
        int d = fyb(i);
        for (int j = d; j < nel; j++) {
            for (int k = j - d; k >= 0; k -= d) {
                if (compare(k, k + d) == 1) swap(k, k + d);
            }
        }
    }
}
