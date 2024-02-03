#include <stdio.h>

unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
{
    for (int i = 0; i < nel - 1; ++i){
        if (less(i, i + 1) == 0){
            return i;
        }
    }
    
    return nel -1;
}