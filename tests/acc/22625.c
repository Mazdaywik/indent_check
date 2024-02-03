void shellsort(long long nel, int (*compare)(long long i, long long j), void (*swap)(long long i, long long j)) {
    if (nel <= 1) return;
    long long j = 2;
    long long temp, sum;
    long long fib[1000] = {1, 1};

    while (fib[j - 1] + fib[j - 2] < nel) {
        fib[j] = fib[j - 2] + fib[j - 1];
        j++;
    }

    for (long long idx = j - 1; idx >= 0; idx--) {
        long long d = fib[idx];
        for (long long i = d; i < nel; i++) {
            for (long long l = i; l >= d && compare(l - d, l) > 0; l -= d) {
                swap(l, l - d);
            }
        }
    }
}