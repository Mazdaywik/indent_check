void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)) {
    unsigned long r = nel - 1, l = 0;
    if (nel < 1){
        return;
    }
    while (l < r) {
        unsigned long r2 = r, l2 = l;
        r = 0;
        for (unsigned long i = l; i < r2; ++i) {
            if (compare(i, i + 1) > 0) {
                swap(i, i + 1);
                r = i;
            }
        }
        l = 0;
        for (unsigned long i = r; i > l2; --i) {
            if (compare(i, i - 1) < 0) {
                swap(i, i - 1);
                l = i;
            }
        }
    }
}