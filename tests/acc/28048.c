int fib(int n) {
    int a = 0, b = 1, tmp;
    for (int i = 0; i < n; i++) {
        tmp = a;
        a = b;
        b = tmp + b;
    }
    return a;
}

int fib_max(int n) {
    int i = 0;
    int f = fib(i);
    while (f < n) {
        i++;
        f = fib(i);
    }
    return i - 1;
}

void shellsort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j)) {
    int f = fib_max(nel);
    int d = fib(f);
    while (d > 0) {
        for (int i = d; i < nel; ++i) {
            for (int j = i - d; j >= 0 && compare(j, j + d) == 1; j -= d)
                swap(j, j + d);
        }
        f-=1;
        d = fib(f);
    }
}