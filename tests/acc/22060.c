void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    unsigned long fib1 = 1, fib2 = 2, fib3 = 3;

    while(fib3 < nel){
        fib3 = fib1 + fib2;

        if(fib3 < nel){
            fib1 = fib2;
            fib2 = fib3;
        }
    }

    unsigned long max_fib =  fib2, pred_fib = fib1;

    while(max_fib >= 1){
        unsigned long i = max_fib;

        while(i < nel){

            long long elem = i;
            long long loc = i - max_fib;

            while(loc >= 0 && compare(loc, elem) == 1){
                swap(elem, loc);
                elem = loc;
                loc -= max_fib;
            }
            i++;
        }

        pred_fib = max_fib - pred_fib;
        max_fib -= pred_fib;
    }
}