unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)) {
    if (nel == 1) return 0;
    unsigned long left = 0, right = nel - 1;

    while (left < right) {
        unsigned long mid = left + (right - left)/2;
        if (less(mid, mid + 1)) left = mid + 1;
        else right = mid;
    }
    return left;
}