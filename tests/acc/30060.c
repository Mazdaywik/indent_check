void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)) {
    if (nel < 2) return;
    unsigned long a = 0, b = nel - 1, cache;

    while (a < b) {
        cache = a;
        for (unsigned long i = a; i < b; ++i) {
            if (compare(i, i + 1) > 0) {
                swap(i, i + 1);
                cache = i;
            }
        }
        b = cache;
        if (a >= b) break;

        cache = b;
        for (unsigned long i = b; i > a; --i) {
            if (compare(i - 1, i) > 0) {
                swap(i - 1, i);
                cache = i;
            }
        }
        a = cache;
    }
}