unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
    unsigned long low = 0, high = nel - 1, mid;
    int res;
    
    if(compare(low) == 1 || compare(high) == -1)
        return nel;

    while(low <= high){
        mid = (low + high) / 2;
        res = compare(mid);
        if(res == 0)
            return mid;
        if(res == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return nel;
}