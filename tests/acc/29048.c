#include <stdlib.h>

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long ind, first=0, last = nel - 1;
    while (first <= last) {
        ind = first + (last - first) / 2; 
        //лучше тем, что не произойдет переполнения типа данных даже при макс.
        //значениях last и first
        if (compare(ind) == 0) {
            return ind;
        }
        else {
            if (compare(ind) == 1) {
            last = ind - 1;
            }
            else {
                first = ind + 1;
            }
        }
    }
    return nel;
}