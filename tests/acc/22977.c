unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    unsigned long start = 0, end = nel - 1, mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (compare(mid) == 0) return mid;
        else {
            if (compare(mid) > 0) {
                if (mid < 1) break;
                else end = mid - 1;
            }
            else start = mid + 1;
        }
    }
    return nel;
}