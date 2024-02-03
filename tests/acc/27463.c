void shellsort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j))
{
    unsigned long d;
    int fib[nel + 3], i = 2, j, loc, k;
    fib[0] = 1;
    fib[1] = 1;
    while (fib[i - 1] + fib[i - 2] <= nel) {
        fib[i] = fib[i - 1] + fib[i - 2];
        i++;
    }
    for (j = i - 1; j >= 1; j--) {
        d = fib[j];
        for (loc = d; loc < nel; loc++) {
            for (k = loc - d; k >= 0 && compare(k, k + d) > 0; k -= d) {
                swap(k, k + d);
            }
        }
    }
}