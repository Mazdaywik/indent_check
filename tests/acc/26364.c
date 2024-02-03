long peak(long n, int (*less)(long x, long y)){
    if (n == 1 || !less(0, 1)){
        return 0;
    }
    for (int i = 1; i < n - 1; i++){
        if (!less(i, i-1) && !less(i, i+1)){
            return i;
        }
    }
    return n-1;
}