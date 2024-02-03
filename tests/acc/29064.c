unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) 
{
    long  a = 0, b = nel - 1;


    while (a <= b) 
    {
        long mi;
        mi = a + (b - a) / 2 ; // если мы будем использовать формулу mi = (a+b) / 2, то может произойти переполнение, а с формулой mi = a + (b - a) / 2 нет
        int cmp = compare(mi);
        
        if (cmp == 0) 
        {
            return mi;
        } else if (cmp == -1) 
        {
            a = mi + 1;
        } else 
        {
            b = mi - 1;
        }
    }

    return nel;
}