 unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    int l = 0;
    int r = nel - 1;
    while(l <= r){
        int m = (l + r)/2;
        if(compare(m) == 0) return m;
        if(compare(m) == 1){
            r = m - 1;
        }
        if(compare(m) == - 1){
            l = m + 1;
        }
    }
    return nel;
}