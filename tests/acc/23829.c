#include <stdio.h>
unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long min_i = 0, max_i = nel - 1, res_i = (nel -1) / 2;
    while (max_i - min_i > 0) {
        if (compare(res_i) == 1) {
            max_i = res_i;
            res_i = (min_i + max_i)/2;
        }
        else if (compare(res_i) == -1) {
            min_i = res_i+1;
            res_i = (min_i + max_i)/2;
        }
        else 
            break;
    }
    if (compare(res_i) == 0)
        return res_i;
    else
        return nel;
}