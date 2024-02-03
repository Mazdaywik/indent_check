unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
    long left, right, mid;
    int p;
    left = 0;
    right = nel - 1;
    while (left < right){
        mid = (left + right) / 2;
        p = compare(mid);
        if (p == 1){
            right = mid; 
        }
        if (p == -1){
            left = mid + 1;
        }
        if (p == 0){
            return mid;
        }
    }
    if (compare(left) == 0){
        return left;
    }
    return nel;
}

