unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
    {
        unsigned long f = 0;
        unsigned long l = nel - 1;
        // printf("chek first element ")
        if (nel == 1) return 0;
        if (less(f, f+1) == 0) return f;
        if (less(l, l-1) == 0) return l;
        for (unsigned long i = f+1; i < l; i++)
        {
            if (less(i, i-1) + less(i, i+1) == 0) return i;
        }
    }