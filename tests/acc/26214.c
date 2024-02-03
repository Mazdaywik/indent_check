unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    unsigned long m, l = 0, r = nel - 1;
    if (compare(0) == 0) {
        return 0;
    }
    while (l + 1 < r){
        m = (l + r) / 2;
        if (compare(m) < 0){
            l = m;
        }
        else {
            r = m;
        }
    }
    if (compare(r) != 0) {
        r = nel;
    }
    return r;
}