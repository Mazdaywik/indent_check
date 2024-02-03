#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
{
        unsigned long res,n,m,k,i;
        if (nel == 1) return 0;
        if(less(1,0)) return 0;
        for (i = 2; i < nel; i++){
            n = i - 2;
            m = i - 1;
            k = i;
            if (less(m, n) == 0 && less(m, k) == 0) return m;
            
        }
        if(less(nel - 2, nel - 1)) return nel - 1;
}