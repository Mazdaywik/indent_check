void shellsort(unsigned long nel,
        int (compare)(unsigned long i, unsigned long j),
        void (swap)(unsigned long i, unsigned long j))
{
    unsigned long fibonacci[50];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    int fib_n = 1;

    while (fibonacci[fib_n] < nel) {
        fibonacci[fib_n + 1] = fibonacci[fib_n] + fibonacci[fib_n - 1];
        if (fibonacci[fib_n + 1] < nel) {
            fib_n++;
        } else {
            break;
        }
    }

    for (int index = fib_n; index > 0; index--) {
        int d = fibonacci[index];
        for (int k = d; k < nel; k++) {
            int loc = k;
            while (loc >= d && compare(loc - d, loc) > 0) {
                swap(loc - d, loc);
                loc -= d;
            }
        }
    }
}
