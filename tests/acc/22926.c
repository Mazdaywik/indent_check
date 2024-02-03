unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
        int first = -1;
        int last = nel;
        while (last > first + 1) {
            // printf("%lu, %lu\n", first, last);
            int midle = (first + last) / 2;
            if (compare(midle) == 0) return midle;
            if (compare(midle) == -1) first = midle;
            else last = midle;
            
        }
        return nel;
}