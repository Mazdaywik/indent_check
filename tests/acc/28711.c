unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)) {
    unsigned long left = 0;
    unsigned long right = nel - 1;
    for (left; left < right;) {
        unsigned long mid = left + (right - left) / 2;
        if (less(mid, mid + 1))
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}