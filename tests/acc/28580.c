unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) 
{ 
    unsigned long l = 0, r = nel - 1, m;
    int res;
    while (l <= r)  {
        m = (l + r)/2;
	res = compare(m);
	if (res == -1)
	    l = m + 1;
	if (res == 1)
	    r = m - 1;
	if (res == 0)
	    return m;
    }
    return nel;
}