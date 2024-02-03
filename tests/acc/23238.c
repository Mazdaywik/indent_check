#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long l = 0;
    unsigned long r = nel - 1;
    //if ((nel - 1) % 2 == 0) m = (nel - 1) / 2;
    //else m = (nel) / 2;
    if (nel == 0)  return nel;
    if (nel == 1 && compare(0) != 0) return nel;
    if (nel == 1 && compare(0) == 0) return 0;
    while (l <= r){
        unsigned long m = (r + l) / 2;
        int k = compare(m);
        if (k > 0){
            r = m - 1;
            //m = (l + r) / 2;
            //m = (r + l) % 2 == 0 ? (r + l) / 2 : (r + l + 1) / 2;
        }
        else if (k < 0){
            l = m + 1;
            //m = (l + r) / 2;
            //m = (r + l) % 2 == 0 ? (r + l) / 2 : (r + l + 1) / 2;
        }
        else return m;
        
    }
    return nel;
}