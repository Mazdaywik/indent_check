unsigned long _binsearch(unsigned long nel, int (*compare)(unsigned long i), unsigned long L, unsigned long R)
{
    unsigned long n = L + (R - L) / 2;
    switch (compare(n))
    {
    case 1:
        if (n == R)
        {
            return nel;
        }
        else
        {
            return _binsearch(nel, compare, L, n);
        }
        break;
    case 0:
        return n;
        break;
    case -1:
        if (n == L)
        {
            return nel;
        }
        else
        {
            return _binsearch(nel, compare, n, R);
        }
        break;
    }
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    return _binsearch(nel, compare, 0, nel);
}