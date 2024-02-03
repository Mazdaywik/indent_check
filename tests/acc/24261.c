unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    unsigned long l = 0, r = nel;
    while (l + 1 < r) {
        unsigned mid = (l + r) / 2;
        if (compare(mid) <= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (compare(l) == 0) {
        return l;
    } else {
        return nel;
    }
}