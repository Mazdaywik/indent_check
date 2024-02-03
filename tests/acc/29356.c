unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    long left = 0;
    long right = (long)nel - 1;
    while (left <= right) {
        long mid = left + (right - left) / 2;
        int c = compare((unsigned long)mid);
        if (c < 0) {
            left = mid + 1;
        } else if (c > 0) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return nel;
}