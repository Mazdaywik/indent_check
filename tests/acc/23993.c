#include <stdio.h>
int a[] = {1,1,1,1,1,1};
int less(unsigned long i, unsigned long j)
{
    if (a[i]<a[j]) return 1;
    else return 0;
}


unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j))
{
    if (nel == 0) return 0;
    for(unsigned long k=0; k<nel; k++) {
        if (k==0) {
            if (nel == 1 || less(k, k+1) == 0) return k;
        }
        else if(k==nel-1) return k;
        else if(less(k, k-1) == 0 && less(k, k+1) == 0) return k;
    }
}

int main(int argc, char** argv)
{
    return 0;
}