void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    unsigned long maxfib(unsigned long n) {
        if (n <= 2) {
            return n - 1;
        } else {
            int a = 1, b = 2, c;
            while (b < n) {
                c = b;
                b = a + b;
                a = c;
            }
            return a;
        }
    }
    if (nel > 1){
        unsigned long d = maxfib(nel);
        while (d > 0) {
            unsigned long i = d;
            while (i < nel) {
                long loc = i - d;
                while (loc>= 0 && compare(loc, loc+d) == 1) {
                    swap(loc, loc + d);
                    loc-=d;
                }
                i+=1;
            }
            d = maxfib(d);
        }
    }
}