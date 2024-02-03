unsigned long binsearch(unsigned long nel, int(*compare)(unsigned long i))
{   
    int mid;
    int left = -1;
    int right = nel;
    while(right - left > 1) {
        mid = (right + left) / 2;
        int res = compare(mid);
        if(res == -1)
            left = mid;
        if(res == 0)
            return mid;
        if(res == 1)
            right = mid;
    }
    return nel;
}