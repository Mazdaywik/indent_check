void shellsortRec(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j), long fib1, long fib2)
{
        long fib3 = fib1 + fib2;
        if (fib3<nel){
            shellsortRec(nel, compare, swap, fib2, fib3);
        }
        long ind = fib2;
        while (ind < nel){
            long loc = ind - fib2;
            while((loc >= 0) && (compare(loc, loc + fib2) == 1)){
                swap(loc, loc+fib2);
                loc -= fib2;
            }
            ind++;
        }
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
        shellsortRec(nel, compare, swap, 1, 1);
}
