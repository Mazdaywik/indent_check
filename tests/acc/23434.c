unsigned long nearest_fib_digit(unsigned long x)
{
    if(x == 0) {
        return 0;
    }
    unsigned long fib0 = 1, fib1 = 1;
    while(fib1 < x) {
        fib1 += fib0;
        fib0 = fib1 - fib0;
    }
    return fib1 == x ? fib1 : fib0;
}


void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    for(unsigned long d = nearest_fib_digit(nel); d > 0; d = nearest_fib_digit(d - 1)) {
        for(unsigned long i = d; i < nel; i++) {
            unsigned long j;
            for(j = i; j >= d && compare(j - d, j) >= 0; j -= d) {
                swap(j - d, j);
            }
        }
    }
}