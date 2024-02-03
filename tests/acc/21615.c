#include <stdio.h>
#include <stdbool.h>

unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
{
         
        int l = 0;
        int r = nel - 1;
        while(l < r){
            int m = (l + r)/2;
            if(less(m + 1 , m) ) r = m;
            else l = m + 1;
        }
        return l;
}

