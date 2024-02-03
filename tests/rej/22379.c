unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) 
{ 
    unsigned long l = 0, r = nel - 1, m;
    while (l <= r)  {
	    m = (l + r)/2;
	    if (compare(m) == -1)
		    l = m + 1;
	    if (compare(m) == 1)
		    r = m - 1;
	    if (compare(m) == 0)
		    return m;
	}
	return nel;
}