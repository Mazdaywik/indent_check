#include <stdio.h>
#include <math.h>

int make_fib(int n)
{
        int a = 1, b = 1, s;
        while (b + a < n)
        {
                s = b;
                b = a + s;
                a = s;
        }
        return b;
}

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j))
{
        int d = make_fib(nel);
        while (d >= 1)
        {
                for (int i = d; i < nel; ++i)
                {
                        int loc = i;
                        while (loc - d >= 0 && compare(loc - d, loc) > 0)
                        {
                                swap(loc - d, loc);
                                loc -= d;
                        }
                }
                if (d == 1)
                {
                        d = 0;
                }
                else
                {
                        d = (int)round(d / ((1 + sqrt(5) / 2.0)));
                }
        }
}