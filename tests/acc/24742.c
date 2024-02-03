#include <stdio.h>

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
        if(nel == 0) return nel;
        unsigned long start = 0, end = nel - 1, cur;
        while(start <= end){
            cur = (start + end)/ 2;
            if (compare(cur) == -1) start = cur + 1;
            else if (compare(cur) == 1) end = cur - 1;
            else return cur;
        }
        return nel;
}