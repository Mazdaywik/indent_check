long binsearch(long size, int (*compare)(int)){
    long lo = 0, hi = size - 1;
    while (hi - lo > 1){
        if (compare((lo+hi)/2) < 0){
            lo = (lo+hi)/2;
        }
        else if (compare((lo+hi)/2) > 0){
            hi = (lo+hi)/2;
        }
        else{
            return (lo+hi)/2;
        }
    }
    if (!compare(lo)){
        return lo;
    }
    if (!compare(hi)){
        return hi;
    }
    return size;
}