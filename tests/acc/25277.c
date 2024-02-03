#include <stdio.h>

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j))
{

    int get_closest_fib(int x)
    {
        int last = 0;
        int current = 1;

        while (current + last < x)
        {

            current += last;

            last = current - last;
        }

        return x == 0 ? 0 : current;
    }
    
    for (size_t d = get_closest_fib(nel); d >= 1; d = get_closest_fib(d - 1))
    {

        for (size_t i = d; i < nel; ++i)
        {
            int j = i - d;
            while (j >= 0 && compare(j, j + d) > 0)
            {

                swap(j + d, j);
                j -= d;
            }
        }
    }
}