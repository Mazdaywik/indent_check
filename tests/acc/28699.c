unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    unsigned long left = 0;
    unsigned long right = nel - 1;
    unsigned long middle = (left + right) / 2;
    while (right - left > 1) {
        middle = (left + right) / 2;
        if (compare(middle) == 0) {
            break;
        }
        if (compare(middle) == 1) {
            right = middle;
        } else {
            left = middle;
        }
    }
    if (compare(middle) == 0) {
        return middle;
    }
    if (compare(left) == 0) {
        return left;
    }
    if (compare(right) == 0) {
        return right;
    }
    return nel;
}