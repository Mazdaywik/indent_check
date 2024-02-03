#include <stddef.h>

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j))
{
    if (nel <= 1) {
        return;
    }
    unsigned long long fib[100] = {0};
    fib[0] = 1;
    fib[1] = 1;
    unsigned long long k = 1;
    for (k=2; nel - fib[k-1] >= fib[k-2]; k++) {
        fib[k] = fib[k-1] + fib[k-2];
    }
    for (unsigned long long i=k-1; i>0; i--) {
        for (size_t r = fib[i]; r < nel; r++) {
            for (size_t l = r; l >= fib[i]; l -= fib[i]) {
                if (compare(l - fib[i], l) == 1) {
                    swap(l - fib[i], l);
                }
                else {
                    break;
                }
            }
        }
    }
}