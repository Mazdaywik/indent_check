unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    unsigned long int i = 0, start = 0, end = nel;
    while (start<end){
        i = (start + end) / 2;
        if (compare(i) == 0)
            return i;
        if (compare(i) == -1)
            start = i+1;
        else
            end = i;
    }
    if (compare(i) == 0)
        return start;
    return nel;
}